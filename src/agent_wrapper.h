// -*- mode: C++ -*-

#ifndef _AGENT_H__
#define _AGENT_H__

#include "node-marisa.h"
#include <string>

class AgentWrap : node::ObjectWrap {
public:
  static void Init(v8::Handle<v8::Object> target);
  static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);
  marisa::Agent& agent() { return agent_; }

private:
  AgentWrap() {}
  ~AgentWrap() {}

  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Handle<v8::Value> Query(const v8::Arguments& args);
  static v8::Handle<v8::Value> Key(const v8::Arguments& args);
  static v8::Handle<v8::Value> SetQuery(const v8::Arguments& args);
  static v8::Handle<v8::Value> SetQuery0(v8::HandleScope& scope, AgentWrap *inst, v8::String::Utf8Value& arg0);
  static v8::Handle<v8::Value> SetQuery1(v8::HandleScope& scope, AgentWrap *inst, v8::String::Utf8Value& arg0, int32_t arg1);
  static v8::Handle<v8::Value> SetQuery2(v8::HandleScope& scope, AgentWrap *inst, int32_t arg0);

  static v8::Persistent<v8::Function> constructor;
  marisa::Agent agent_;
  std::string query_str_;
};

#endif
