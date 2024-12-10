///
/// HybridMQTTSpec.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/**
 * A Swift protocol representing the MQTT HybridObject.
 * Implement this protocol to create Swift-based instances of MQTT.
 *
 * When implementing this protocol, make sure to initialize `hybridContext` - example:
 * ```
 * public class HybridMQTT : HybridMQTTSpec {
 *   // Initialize HybridContext
 *   var hybridContext = margelo.nitro.HybridContext()
 *
 *   // Return size of the instance to inform JS GC about memory pressure
 *   var memorySize: Int {
 *     return getSizeOf(self)
 *   }
 *
 *   // ...
 * }
 * ```
 */
public protocol HybridMQTTSpec: AnyObject, HybridObjectSpec {
  // Properties
  

  // Methods
  func connect(clientID: String, host: String, port: Double) throws -> Void
  func publish(topic: String, message: String) throws -> Void
  func subscribe(topic: String) throws -> Void
  func setOnMessageReceived(callback: @escaping ((_ topic: String, _ message: String) -> Void)) throws -> Void
  func isConnected() throws -> Promise<ConnectionState>
}
