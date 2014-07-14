#include "agent_wrapper.h"
#include "query.h"
#include "key.h"

using namespace v8;
using namespace node;

Persistent<Function> AgentWrap::constructor;

Handle<Value> CreateAgent(const Arguments& args) {
  HandleScope scope;
  return scope.Close(AgentWrap::NewInstance(args));
}

void AgentWrap::Init(Handle<Object> target) {
  HandleScope scope;

  Local<FunctionTemplate> tpl = FunctionTemplate::New(AgentWrap::New);
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(String::NewSymbol("Agent"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "query", AgentWrap::Query);
  NODE_SET_PROTOTYPE_METHOD(tpl, "key", AgentWrap::Key);
  NODE_SET_PROTOTYPE_METHOD(tpl, "set_query", AgentWrap::SetQuery);
  NODE_SET_PROTOTYPE_METHOD(tpl, "setQuery", AgentWrap::SetQuery);

  constructor = Persistent<Function>::New(tpl->GetFunction());

  target->Set(String::NewSymbol("createAgent"), FunctionTemplate::New(CreateAgent)->GetFunction());
}

Handle<Value> AgentWrap::New(const Arguments& args) {
  HandleScope scope;

  AgentWrap *inst = new AgentWrap();
  inst->Wrap(args.This());

  return args.This();
}

Handle<Value> AgentWrap::NewInstance(const Arguments& args) {
  HandleScope scope;

  const int argc = args.Length();
  Handle<Value>* argv = new Handle<Value>[argc];
  for (int i = 0; i < argc; i++) {
    argv[i] = args[i];
  }

  Local<Object> result = constructor->NewInstance(argc, argv);

  delete[] argv;

  return scope.Close(result);
}

Handle<Value> AgentWrap::Query(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    AgentWrap *inst = ObjectWrap::Unwrap<AgentWrap>(args.This());
    Local<Object> thisObj = args.This();
    Handle<Value> result = QueryWrap::NewInstanceFromAgent(thisObj);

    return result;
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> AgentWrap::Key(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    AgentWrap *inst = ObjectWrap::Unwrap<AgentWrap>(args.This());
    Local<Object> thisObj = args.This();
    Handle<Value> result = KeyWrap::NewInstanceFromAgent(thisObj);

    return result;
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> AgentWrap::SetQuery(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 1 && IS_STRING(0)) {
    AgentWrap *inst = ObjectWrap::Unwrap<AgentWrap>(args.This());
    String::Utf8Value arg0(args[0]->ToString());
    return AgentWrap::SetQuery0(scope, inst, arg0);
  }

  if (args.Length() == 2 && IS_STRING(0) && IS_INT32(1)) {
    AgentWrap *inst = ObjectWrap::Unwrap<AgentWrap>(args.This());
    String::Utf8Value arg0(args[0]->ToString());
    int32_t arg1 = args[1]->Int32Value();
    return AgentWrap::SetQuery1(scope, inst, arg0, arg1);
  }

  if (args.Length() == 1 && IS_INT32(0)) {
    AgentWrap *inst = ObjectWrap::Unwrap<AgentWrap>(args.This());
    int32_t arg0 = args[0]->Int32Value();
    return AgentWrap::SetQuery2(scope, inst, arg0);
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> AgentWrap::SetQuery0(HandleScope& scope, AgentWrap *inst, String::Utf8Value& arg0) {
  inst->query_str_ = *arg0;
  inst->agent_.set_query(inst->query_str_.c_str());
  return Undefined();
}

Handle<Value> AgentWrap::SetQuery1(HandleScope& scope, AgentWrap *inst, String::Utf8Value& arg0, int32_t arg1) {
  inst->query_str_ = std::string(*arg0, arg1);
  inst->agent_.set_query(inst->query_str_.c_str());
  return Undefined();
}

Handle<Value> AgentWrap::SetQuery2(HandleScope& scope, AgentWrap *inst, int32_t arg0) {
  // Reverse lookup the key with key_id.
  inst->agent_.set_query(static_cast<uint32_t>(arg0));
  return Undefined();
}

