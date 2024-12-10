///
/// JHybridMQTTSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "JHybridMQTTSpec.hpp"



#include <string>
#include <functional>
#include "JFunc_void_std__string_std__string.hpp"

namespace margelo::nitro::mqtt {

  jni::local_ref<JHybridMQTTSpec::jhybriddata> JHybridMQTTSpec::initHybrid(jni::alias_ref<jhybridobject> jThis) {
    return makeCxxInstance(jThis);
  }

  void JHybridMQTTSpec::registerNatives() {
    registerHybrid({
      makeNativeMethod("initHybrid", JHybridMQTTSpec::initHybrid),
    });
  }

  size_t JHybridMQTTSpec::getExternalMemorySize() noexcept {
    static const auto method = _javaPart->getClass()->getMethod<jlong()>("getMemorySize");
    return method(_javaPart);
  }

  // Properties
  

  // Methods
  bool JHybridMQTTSpec::connect(const std::string& clientID, const std::string& host, double port) {
    static const auto method = _javaPart->getClass()->getMethod<jboolean(jni::alias_ref<jni::JString> /* clientID */, jni::alias_ref<jni::JString> /* host */, double /* port */)>("connect");
    auto __result = method(_javaPart, jni::make_jstring(clientID), jni::make_jstring(host), port);
    return static_cast<bool>(__result);
  }
  void JHybridMQTTSpec::publish(const std::string& topic, const std::string& message) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<jni::JString> /* topic */, jni::alias_ref<jni::JString> /* message */)>("publish");
    method(_javaPart, jni::make_jstring(topic), jni::make_jstring(message));
  }
  void JHybridMQTTSpec::subscribe(const std::string& topic) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<jni::JString> /* topic */)>("subscribe");
    method(_javaPart, jni::make_jstring(topic));
  }
  void JHybridMQTTSpec::setOnMessageReceived(const std::function<void(const std::string& /* topic */, const std::string& /* message */)>& callback) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<JFunc_void_std__string_std__string::javaobject> /* callback */)>("setOnMessageReceived");
    method(_javaPart, JFunc_void_std__string_std__string::fromCpp(callback));
  }

} // namespace margelo::nitro::mqtt
