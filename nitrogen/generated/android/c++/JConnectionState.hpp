///
/// JConnectionState.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include <fbjni/fbjni.h>
#include "ConnectionState.hpp"

namespace margelo::nitro::mqtt {

  using namespace facebook;

  /**
   * The C++ JNI bridge between the C++ enum "ConnectionState" and the the Kotlin enum "ConnectionState".
   */
  struct JConnectionState final: public jni::JavaClass<JConnectionState> {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/mqtt/ConnectionState;";

  public:
    /**
     * Convert this Java/Kotlin-based enum to the C++ enum ConnectionState.
     */
    [[maybe_unused]]
    ConnectionState toCpp() const {
      static const auto clazz = javaClassStatic();
      static const auto fieldOrdinal = clazz->getField<int>("_ordinal");
      int ordinal = this->getFieldValue(fieldOrdinal);
      return static_cast<ConnectionState>(ordinal);
    }

  public:
    /**
     * Create a Java/Kotlin-based enum with the given C++ enum's value.
     */
    [[maybe_unused]]
    static jni::alias_ref<JConnectionState> fromCpp(ConnectionState value) {
      static const auto clazz = javaClassStatic();
      static const auto fieldCONNECTED = clazz->getStaticField<JConnectionState>("CONNECTED");
      static const auto fieldDISCONNECTED = clazz->getStaticField<JConnectionState>("DISCONNECTED");
      static const auto fieldCONNECTING = clazz->getStaticField<JConnectionState>("CONNECTING");
      
      switch (value) {
        case ConnectionState::CONNECTED:
          return clazz->getStaticFieldValue(fieldCONNECTED);
        case ConnectionState::DISCONNECTED:
          return clazz->getStaticFieldValue(fieldDISCONNECTED);
        case ConnectionState::CONNECTING:
          return clazz->getStaticFieldValue(fieldCONNECTING);
        default:
          std::string stringValue = std::to_string(static_cast<int>(value));
          throw std::invalid_argument("Invalid enum value (" + stringValue + "!");
      }
    }
  };

} // namespace margelo::nitro::mqtt
