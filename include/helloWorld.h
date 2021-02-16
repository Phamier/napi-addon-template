#ifndef HELLO_WORLD_H_
#define HELLO_WORLD_H_

#include <napi.h>

// "Hello World" function
Napi::Value helloWorld(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  return Napi::String::New(env, "Hello World!");
}

#endif