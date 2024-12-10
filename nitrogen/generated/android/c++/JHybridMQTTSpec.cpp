///
/// JHybridMQTTSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "JHybridMQTTSpec.hpp"

// Forward declaration of `ConnectionState` to properly resolve imports.
namespace margelo::nitro::mqtt { enum class ConnectionState; }

#include <NitroModules/Promise.hpp>
#include "ConnectionState.hpp"
#include <NitroModules/JPromise.hpp>
#include "JConnectionState.hpp"
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
  void JHybridMQTTSpec::connect(const std::string& clientID, const std::string& host, double port) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<jni::JString> /* clientID */, jni::alias_ref<jni::JString> /* host */, double /* port */)>("connect");
    method(_javaPart, jni::make_jstring(clientID), jni::make_jstring(host), port);
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
  std::shared_ptr<Promise<ConnectionState>> JHybridMQTTSpec::isConnected() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JPromise::javaobject>()>("isConnected");
    auto __result = method(_javaPart);
    return [&]() {
      auto __promise = Promise<ConnectionState>::create();
      __result->cthis()->addOnResolvedListener([=](const jni::alias_ref<jni::JObject>& __boxedResult) {
        auto __result = jni::static_ref_cast<JConnectionState>(__boxedResult);
        __promise->resolve(__result->toCpp());
      });
      __result->cthis()->addOnRejectedListener([=](const jni::alias_ref<jni::JThrowable>& __throwable) {
        jni::JniException __jniError(__throwable);
        __promise->reject(std::make_exception_ptr(__jniError));
      });
      return __promise;
    }();
  }

} // namespace margelo::nitro::mqtt
