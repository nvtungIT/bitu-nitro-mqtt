import CocoaMQTT

class HybridMQTT: HybridMQTTSpec {
     var hybridContext = margelo.nitro.HybridContext()

   var memorySize: Int {
     return getSizeOf(self)
   }
    var mqtt: CocoaMQTT?

  public func connect(clientID: String, host: String, port: Double) {
        // Safely cast `port` to UInt16
        guard let portUInt16 = UInt16(exactly: port) else {
            print("Invalid port value")
            return
        }
        
        let mqttClient = CocoaMQTT(clientID: clientID, host: host, port: portUInt16)
        mqttClient.keepAlive = 60
         mqttClient.delegate = self 
        mqttClient.connect()
        mqtt = mqttClient
    }
    public func publish(topic: String, message: String) {
        mqtt?.publish(topic, withString: message)
    }

    public func subscribe(topic: String) {
        mqtt?.subscribe(topic)
    }

    public func disconnect() {
        mqtt?.disconnect()
        mqtt = nil
    }
    public func isConnected() -> Bool {
        return mqtt?.connState == .connected
    }
}
