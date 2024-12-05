///
/// HybridMQTTSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "HybridMQTTSpec.hpp"

namespace margelo::nitro::math {

  void HybridMQTTSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridMethod("connect", &HybridMQTTSpec::connect);
      prototype.registerHybridMethod("publish", &HybridMQTTSpec::publish);
      prototype.registerHybridMethod("subscribe", &HybridMQTTSpec::subscribe);
      prototype.registerHybridMethod("disconnect", &HybridMQTTSpec::disconnect);
      prototype.registerHybridMethod("isConnected", &HybridMQTTSpec::isConnected);
    });
  }

} // namespace margelo::nitro::math