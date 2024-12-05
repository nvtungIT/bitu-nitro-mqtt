///
/// JHybridMathSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "JHybridMathSpec.hpp"





namespace margelo::nitro::math {

  jni::local_ref<JHybridMathSpec::jhybriddata> JHybridMathSpec::initHybrid(jni::alias_ref<jhybridobject> jThis) {
    return makeCxxInstance(jThis);
  }

  void JHybridMathSpec::registerNatives() {
    registerHybrid({
      makeNativeMethod("initHybrid", JHybridMathSpec::initHybrid),
    });
  }

  size_t JHybridMathSpec::getExternalMemorySize() noexcept {
    static const auto method = _javaPart->getClass()->getMethod<jlong()>("getMemorySize");
    return method(_javaPart);
  }

  // Properties
  

  // Methods
  double JHybridMathSpec::add(double a, double b) {
    static const auto method = _javaPart->getClass()->getMethod<double(double /* a */, double /* b */)>("add");
    auto __result = method(_javaPart, a, b);
    return __result;
  }

} // namespace margelo::nitro::math
