#include <jni.h>
#include "NitroMQTTOnLoad.hpp"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
  return margelo::nitro::mqtt::initialize(vm);
}
