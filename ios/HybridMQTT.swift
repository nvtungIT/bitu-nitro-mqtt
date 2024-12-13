import Foundation
import CocoaMQTT
import NitroModules

typealias JSON = [String: Any?]

class HybridMQTT: HybridMQTTSpec {
    var hybridContext = margelo.nitro.HybridContext()
    var memorySize: Int {
        return getSizeOf(self)
    }
    
    private var mqttClient: CocoaMQTT5?
    private var onMessageReceived: ((String, String) -> Void)?


    public func connect(clientID: String, host: String, port: Double) throws -> AnyValue {
    if mqttClient == nil {
        let mqtt = CocoaMQTT5(clientID: clientID, host: host, port: UInt16(port))
        self.mqttClient = mqtt
        self.mqttClient?.delegate = self
    }
       return mqttClient
}

    public func publish(topic: String, message: String) throws -> Double {
        let payload: [UInt8] = Array(message.utf8)
        let properties = MqttPublishProperties()
        let cocoaMqttMessage = CocoaMQTT5Message(topic: topic, payload: payload)
        let code = mqttClient?.publish(cocoaMqttMessage, DUP: false, retained: false, properties: properties) ?? 0
        return Double(code)
    }


    public func subscribe(topic: String) throws  {
         mqttClient?.subscribe(topic)
    }
    
    var subs: [Any] = []

   public func setOnMessageReceived(callback: @escaping ((_ topic: String, _ message: String) -> Void)) throws {
       subs.append(callback)
    }

    
}

extension HybridMQTT: CocoaMQTT5Delegate {
    func mqtt5(_ mqtt5: CocoaMQTT5, didConnectAck ack: CocoaMQTTCONNACKReasonCode, connAckData: MqttDecodeConnAck?) {
        
    }
    
    func mqtt5(_ mqtt5: CocoaMQTT5, didPublishMessage message: CocoaMQTT5Message, id: UInt16) {
        
    }
    
    func mqtt5(_ mqtt5: CocoaMQTT5, didPublishAck id: UInt16, pubAckData: MqttDecodePubAck?) {
        
    }
    
    func mqtt5(_ mqtt5: CocoaMQTT5, didPublishRec id: UInt16, pubRecData: MqttDecodePubRec?) {
        
    }
    
    func mqtt5(_ mqtt5: CocoaMQTT5, didReceiveMessage message: CocoaMQTT5Message, id: UInt16, publishData: MqttDecodePublish?) {
        let topicStr = message.topic
        let jsonStr = message.string
        var payload: JSON = .init()
        if let data = jsonStr?.data(using: .utf8) {
            if let json = try? JSONSerialization.jsonObject(with: data, options: .mutableContainers) as? JSON {
                payload = json
            }
            payload["mqtt_topic"] = topicStr
        }
    }
    
    func mqtt5(_ mqtt5: CocoaMQTT5, didSubscribeTopics success: NSDictionary, failed: [String], subAckData: MqttDecodeSubAck?) {
        
    }
    
    func mqtt5(_ mqtt5: CocoaMQTT5, didUnsubscribeTopics topics: [String], unsubAckData: MqttDecodeUnsubAck?) {
        
    }
    
    func mqtt5(_ mqtt5: CocoaMQTT5, didReceiveDisconnectReasonCode reasonCode: CocoaMQTTDISCONNECTReasonCode) {
        
    }
    
    func mqtt5(_ mqtt5: CocoaMQTT5, didReceiveAuthReasonCode reasonCode: CocoaMQTTAUTHReasonCode) {
        
    }
    
    func mqtt5DidPing(_ mqtt5: CocoaMQTT5) {
        
    }
    
    func mqtt5DidReceivePong(_ mqtt5: CocoaMQTT5) {
        
    }
    
    func mqtt5DidDisconnect(_ mqtt5: CocoaMQTT5, withError err: (any Error)?) {
        
    }
}



