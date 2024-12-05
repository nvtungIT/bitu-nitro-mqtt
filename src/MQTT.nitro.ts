import { type HybridObject } from 'react-native-nitro-modules'

export interface MQTT
  extends HybridObject<{ ios: 'swift'; android: 'kotlin' }> {
  connect(clientID: string, host: string, port: number): void
  publish(topic: string, message: string): void
  subscribe(topic: string): void
  disconnect(): void
  isConnected(): boolean
}
