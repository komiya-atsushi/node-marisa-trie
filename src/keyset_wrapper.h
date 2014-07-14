// -*- mode: C++ -*-

#ifndef _KEYSET_H__
#define _KEYSET_H__

#include "node-marisa.h"
#include "key.h"

class KeysetWrap : node::ObjectWrap {
public:
  static void Init(v8::Handle<v8::Object> target);
  static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);
  marisa::Keyset& keyset() { return keyset_; }

private:
  KeysetWrap() {}
  ~KeysetWrap() {}

  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Handle<v8::Value> PushBack(const v8::Arguments& args);
  static v8::Handle<v8::Value> PushBack0(v8::HandleScope& scope, KeysetWrap *inst, KeyWrap *arg0);
  static v8::Handle<v8::Value> PushBack1(v8::HandleScope& scope, KeysetWrap *inst, KeyWrap *arg0, int32_t arg1);
  static v8::Handle<v8::Value> PushBack2(v8::HandleScope& scope, KeysetWrap *inst, v8::String::Utf8Value& arg0);
  static v8::Handle<v8::Value> PushBack3(v8::HandleScope& scope, KeysetWrap *inst, v8::String::Utf8Value& arg0, int32_t arg1, double arg2);
  static v8::Handle<v8::Value> NumKeys(const v8::Arguments& args);
  static v8::Handle<v8::Value> Empty(const v8::Arguments& args);
  static v8::Handle<v8::Value> Size(const v8::Arguments& args);
  static v8::Handle<v8::Value> TotalLength(const v8::Arguments& args);
  static v8::Handle<v8::Value> Reset(const v8::Arguments& args);
  static v8::Handle<v8::Value> Clear(const v8::Arguments& args);
  static v8::Handle<v8::Value> Swap(const v8::Arguments& args);

  static v8::Persistent<v8::Function> constructor;
  marisa::Keyset keyset_;
};

#endif
