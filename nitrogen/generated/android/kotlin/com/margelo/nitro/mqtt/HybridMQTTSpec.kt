///
/// HybridMQTTSpec.kt
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

package com.margelo.nitro.mqtt

import android.util.Log
import androidx.annotation.Keep
import com.facebook.jni.HybridData
import com.facebook.proguard.annotations.DoNotStrip
import com.margelo.nitro.core.*

/**
 * A Kotlin class representing the MQTT HybridObject.
 * Implement this abstract class to create Kotlin-based instances of MQTT.
 */
@DoNotStrip
@Keep
@Suppress("RedundantSuppression", "KotlinJniMissingFunction", "PropertyName", "RedundantUnitReturnType", "unused")
abstract class HybridMQTTSpec: HybridObject() {
  @DoNotStrip
  private var mHybridData: HybridData = initHybrid()

  init {
    // Pass this `HybridData` through to it's base class,
    // to represent inheritance to JHybridObject on C++ side
    super.updateNative(mHybridData)
  }

  /**
   * Call from a child class to initialize HybridData with a child.
   */
  override fun updateNative(hybridData: HybridData) {
    mHybridData = hybridData
  }

  // Properties
  

  // Methods
  @DoNotStrip
  @Keep
  abstract fun connect(clientID: String, host: String, port: Double): Boolean
  
  @DoNotStrip
  @Keep
  abstract fun publish(topic: String, message: String): Double
  
  @DoNotStrip
  @Keep
  abstract fun subscribe(topic: String): Unit
  
  @DoNotStrip
  @Keep
  abstract fun setOnMessageReceived(callback: (topic: String, message: String) -> Unit): Unit
  
  @DoNotStrip
  @Keep
  private fun setOnMessageReceived(callback: Func_void_std__string_std__string): Unit {
    val __result = setOnMessageReceived(callback.toLambda())
    return __result
  }

  private external fun initHybrid(): HybridData

  companion object {
    private const val TAG = "HybridMQTTSpec"
    init {
      try {
        Log.i(TAG, "Loading NitroMQTT C++ library...")
        System.loadLibrary("NitroMQTT")
        Log.i(TAG, "Successfully loaded NitroMQTT C++ library!")
      } catch (e: Error) {
        Log.e(TAG, "Failed to load NitroMQTT C++ library! Is it properly installed and linked? " +
                    "Is the name correct? (see `CMakeLists.txt`, at `add_library(...)`)", e)
        throw e
      }
    }
  }
}
