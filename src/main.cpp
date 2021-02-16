#include <napi.h>
#include "helloWorld.h"

// Module Inizialization
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "helloWorld"), Napi::Function::New<helloWorld>(env));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)