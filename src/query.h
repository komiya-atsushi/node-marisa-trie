// -*- mode: C++ -*-

#ifndef _QUERY_H__
#define _QUERY_H__

#include "node-marisa.h"

class QueryWrap : node::ObjectWrap {
public:
  static void Init(v8::Handle<v8::Object> target);
  static v8::Handle<v8::Value> NewInstanceFromAgent(v8::Local<v8::Object>& agent);
  marisa::Query& query() { return query_; }

private:
  QueryWrap(marisa::Query query) : query_(query) {}
  ~QueryWrap() {}

  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Handle<v8::Value> Ptr(const v8::Arguments& args);
  static v8::Handle<v8::Value> Length(const v8::Arguments& args);
  static v8::Handle<v8::Value> Id(const v8::Arguments& args);

  static v8::Persistent<v8::Function> constructor;
  marisa::Query query_;
};

#endif
