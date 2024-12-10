import Foundation
import CocoaMQTT
import NitroModules

class HybridMQTT: HybridMQTTSpec {
  
    
    var hybridContext = margelo.nitro.HybridContext()
    var memorySize: Int {
        return getSizeOf(self)
    }
    
    private var mqttClient: CocoaMQTT5?
    private var onMessageReceived: ((String, String) -> Void)?


    public func connect(clientID: String, host: String, port: Double) throws {
        if mqttClient == nil {
            let mqtt = CocoaMQTT5(clientID: clientID, host: host, port: UInt16(port))
            self.mqttClient = mqtt
            mqtt.connect()
        }
    }

    public func publish(topic: String, message: String) throws {
        let payload: [UInt8] = Array(message.utf8)
        let properties = MqttPublishProperties()
        let cocoaMqttMessage = CocoaMQTT5Message(topic: topic, payload: payload)
        mqttClient?.publish(cocoaMqttMessage, DUP: false, retained: false, properties: properties)
    }


    public func subscribe(topic: String) throws {
        mqttClient?.subscribe(topic)
    }

    public func setOnMessageReceived(callback: @escaping ((_ topic: String, _ message: String) -> Void)) throws {
        mqttClient?.didReceiveMessage = { mqtt, message, id, decodePublish in
            let topic = message.topic
            if let payloadString = String(data: Data(message.payload), encoding: .utf8) {
                callback(topic, payloadString)
            } else {
                print("Error decoding message payload")
            }
        }
    }


    public func isConnected() throws -> CocoaMQTTConnState {
        return CocoaMQTTConnState(rawValue: (mqttClient?.connState)!.rawValue) ?? <#default value#>
    }

}

