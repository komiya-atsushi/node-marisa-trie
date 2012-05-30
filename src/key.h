// -*- mode: C++ -*-

#ifndef _KEY_H__
#define _KEY_H__

#include "node-marisa.h"
#include "agent.h"

class KeyWrap : node::ObjectWrap {
public:
  static void Init(v8::Handle<v8::Object> target);
  static v8::Handle<v8::Value> NewInstanceFromAgent(v8::Local<v8::Object>& agent);
  marisa::Key& key() { return key_; }

private:
  KeyWrap(marisa::Key& key) : key_(key) {}
  ~KeyWrap() {}

  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Handle<v8::Value> Ptr(const v8::Arguments& args);
  static v8::Handle<v8::Value> Length(const v8::Arguments& args);
  static v8::Handle<v8::Value> Id(const v8::Arguments& args);

  static v8::Persistent<v8::Function> constructor;
  marisa::Key key_;
};

#endif
