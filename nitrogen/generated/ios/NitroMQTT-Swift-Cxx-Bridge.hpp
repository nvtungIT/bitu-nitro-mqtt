///
/// NitroMQTT-Swift-Cxx-Bridge.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

// Forward declarations of C++ defined types
// Forward declaration of `HybridMQTTSpec` to properly resolve imports.
namespace margelo::nitro::mqtt { class HybridMQTTSpec; }
// Forward declaration of `HybridMathSpec` to properly resolve imports.
namespace margelo::nitro::mqtt { class HybridMathSpec; }

// Forward declarations of Swift defined types
// Forward declaration of `HybridMQTTSpecCxx` to properly resolve imports.
namespace NitroMQTT { class HybridMQTTSpecCxx; }
// Forward declaration of `HybridMathSpecCxx` to properly resolve imports.
namespace NitroMQTT { class HybridMathSpecCxx; }

// Include C++ defined types
#include "HybridMQTTSpec.hpp"
#include "HybridMathSpec.hpp"
#include <functional>
#include <memory>
#include <string>

/**
 * Contains specialized versions of C++ templated types so they can be accessed from Swift,
 * as well as helper functions to interact with those C++ types from Swift.
 */
namespace margelo::nitro::mqtt::bridge::swift {

  // pragma MARK: std::shared_ptr<margelo::nitro::mqtt::HybridMathSpec>
  /**
   * Specialized version of `std::shared_ptr<margelo::nitro::mqtt::HybridMathSpec>`.
   */
  using std__shared_ptr_margelo__nitro__mqtt__HybridMathSpec_ = std::shared_ptr<margelo::nitro::mqtt::HybridMathSpec>;
  std::shared_ptr<margelo::nitro::mqtt::HybridMathSpec> create_std__shared_ptr_margelo__nitro__mqtt__HybridMathSpec_(void* _Nonnull swiftUnsafePointer);
  void* _Nonnull get_std__shared_ptr_margelo__nitro__mqtt__HybridMathSpec_(std__shared_ptr_margelo__nitro__mqtt__HybridMathSpec_ cppType);
  
  // pragma MARK: std::function<void(const std::string& /* topic */, const std::string& /* message */)>
  /**
   * Specialized version of `std::function<void(const std::string&, const std::string&)>`.
   */
  using Func_void_std__string_std__string = std::function<void(const std::string& /* topic */, const std::string& /* message */)>;
  /**
   * Wrapper class for a `std::function<void(const std::string& / * topic * /, const std::string& / * message * /)>`, this can be used from Swift.
   */
  class Func_void_std__string_std__string_Wrapper final {
  public:
    explicit Func_void_std__string_std__string_Wrapper(const std::function<void(const std::string& /* topic */, const std::string& /* message */)>& func): _function(func) {}
    explicit Func_void_std__string_std__string_Wrapper(std::function<void(const std::string& /* topic */, const std::string& /* message */)>&& func): _function(std::move(func)) {}
    inline void call(std::string topic, std::string message) const {
      _function(topic, message);
    }
  private:
    std::function<void(const std::string& /* topic */, const std::string& /* message */)> _function;
  };
  inline Func_void_std__string_std__string create_Func_void_std__string_std__string(void* _Nonnull closureHolder, void(* _Nonnull call)(void* _Nonnull /* closureHolder */, std::string, std::string), void(* _Nonnull destroy)(void* _Nonnull)) {
    std::shared_ptr<void> sharedClosureHolder(closureHolder, destroy);
    return Func_void_std__string_std__string([sharedClosureHolder, call](const std::string& topic, const std::string& message) -> void {
      call(sharedClosureHolder.get(), topic, message);
    });
  }
  inline std::shared_ptr<Func_void_std__string_std__string_Wrapper> share_Func_void_std__string_std__string(const Func_void_std__string_std__string& value) {
    return std::make_shared<Func_void_std__string_std__string_Wrapper>(value);
  }
  
  // pragma MARK: std::shared_ptr<margelo::nitro::mqtt::HybridMQTTSpec>
  /**
   * Specialized version of `std::shared_ptr<margelo::nitro::mqtt::HybridMQTTSpec>`.
   */
  using std__shared_ptr_margelo__nitro__mqtt__HybridMQTTSpec_ = std::shared_ptr<margelo::nitro::mqtt::HybridMQTTSpec>;
  std::shared_ptr<margelo::nitro::mqtt::HybridMQTTSpec> create_std__shared_ptr_margelo__nitro__mqtt__HybridMQTTSpec_(void* _Nonnull swiftUnsafePointer);
  void* _Nonnull get_std__shared_ptr_margelo__nitro__mqtt__HybridMQTTSpec_(std__shared_ptr_margelo__nitro__mqtt__HybridMQTTSpec_ cppType);

} // namespace margelo::nitro::mqtt::bridge::swift
