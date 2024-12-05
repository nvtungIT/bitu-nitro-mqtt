import { NitroModules, type HybridObject } from 'react-native-nitro-modules'
interface Math extends HybridObject {
  add(a: number, b: number): number
}
interface MQTT extends HybridObject<{ ios: 'swift'; android: 'kotlin' }> {
  connect(clientID: string, host: string, port: number): void
  publish(topic: string, message: string): void
  subscribe(topic: string): void
  disconnect(): void
  isConnected(): boolean
}
// TODO: Export all HybridObjects here
export const math = NitroModules.createHybridObject<Math>('Math')
export const mqtt = NitroModules.createHybridObject<MQTT>('MQTT')