import { type HybridObject } from 'react-native-nitro-modules'

export interface MQTT
  extends HybridObject<{ ios: 'swift'; android: 'kotlin' }> {
  /**
   * Connect to an MQTT broker.
   * @param clientID - The client ID to identify the connection.
   * @param host - The broker host.
   * @param port - The broker port.
   */
  connect(clientID: string, host: string, port: number): void

  /**
   * Publish a message to a specific topic.
   * @param topic - The topic to publish to.
   * @param message - The message content.
   */
  publish(topic: string, message: string): void

  /**
   * Subscribe to a specific topic.
   * @param topic - The topic to subscribe to.
   */
  subscribe(topic: string): void

  /**
   * Set a callback to handle received messages.
   * @param callback - A function invoked when a message is received.
   */
  setOnMessageReceived(callback: (topic: string, message: string) => void): void
}
