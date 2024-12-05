///
/// NitroMQTTAutolinking.mm
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#import <Foundation/Foundation.h>
#import <NitroModules/HybridObjectRegistry.hpp>
#import "NitroMQTT-Swift-Cxx-Umbrella.hpp"
#import <type_traits>

#include "HybridMathSpecSwift.hpp"
#include "HybridMQTTSpecSwift.hpp"

@interface NitroMQTTAutolinking : NSObject
@end

@implementation NitroMQTTAutolinking

+ (void) load {
  using namespace margelo::nitro;
  using namespace margelo::nitro::mqtt;

  HybridObjectRegistry::registerHybridObjectConstructor(
    "Math",
    []() -> std::shared_ptr<HybridObject> {
      std::shared_ptr<margelo::nitro::mqtt::HybridMathSpec> hybridObject = NitroMQTT::NitroMQTTAutolinking::createMath();
      return hybridObject;
    }
  );
  HybridObjectRegistry::registerHybridObjectConstructor(
    "MQTT",
    []() -> std::shared_ptr<HybridObject> {
      std::shared_ptr<margelo::nitro::mqtt::HybridMQTTSpec> hybridObject = NitroMQTT::NitroMQTTAutolinking::createMQTT();
      return hybridObject;
    }
  );
}

@end