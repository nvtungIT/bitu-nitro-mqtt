///
/// HybridMQTTSpecSwift.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include "HybridMQTTSpec.hpp"

// Forward declaration of `HybridMQTTSpecCxx` to properly resolve imports.
namespace NitroMQTT { class HybridMQTTSpecCxx; }



#include <string>
#include <functional>

#if __has_include(<NitroModules/HybridContext.hpp>)
#include <NitroModules/HybridContext.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

#include "NitroMQTT-Swift-Cxx-Umbrella.hpp"

namespace margelo::nitro::mqtt {

  /**
   * The C++ part of HybridMQTTSpecCxx.swift.
   *
   * HybridMQTTSpecSwift (C++) accesses HybridMQTTSpecCxx (Swift), and might
   * contain some additional bridging code for C++ <> Swift interop.
   *
   * Since this obviously introduces an overhead, I hope at some point in
   * the future, HybridMQTTSpecCxx can directly inherit from the C++ class HybridMQTTSpec
   * to simplify the whole structure and memory management.
   */
  class HybridMQTTSpecSwift: public virtual HybridMQTTSpec {
  public:
    // Constructor from a Swift instance
    explicit HybridMQTTSpecSwift(const NitroMQTT::HybridMQTTSpecCxx& swiftPart):
      HybridObject(HybridMQTTSpec::TAG),
      _swiftPart(swiftPart) { }

  public:
    // Get the Swift part
    inline NitroMQTT::HybridMQTTSpecCxx getSwiftPart() noexcept { return _swiftPart; }

  public:
    // Get memory pressure
    inline size_t getExternalMemorySize() noexcept override {
      return _swiftPart.getMemorySize();
    }

  public:
    // Properties
    

  public:
    // Methods
    inline bool connect(const std::string& clientID, const std::string& host, double port) override {
      auto __result = _swiftPart.connect(clientID, host, std::forward<decltype(port)>(port));
      return __result;
    }
    inline double publish(const std::string& topic, const std::string& message) override {
      auto __result = _swiftPart.publish(topic, message);
      return __result;
    }
    inline void subscribe(const std::string& topic) override {
      _swiftPart.subscribe(topic);
    }
    inline void setOnMessageReceived(const std::function<void(const std::string& /* topic */, const std::string& /* message */)>& callback) override {
      _swiftPart.setOnMessageReceived(callback);
    }

  private:
    NitroMQTT::HybridMQTTSpecCxx _swiftPart;
  };

} // namespace margelo::nitro::mqtt
