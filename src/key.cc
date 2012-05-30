#include "key.h"

using namespace v8;
using namespace node;

Persistent<Function> KeyWrap::constructor;

void KeyWrap::Init(Handle<Object> target) {
  HandleScope scope;

  Local<FunctionTemplate> tpl = FunctionTemplate::New(KeyWrap::New);
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(String::NewSymbol("Key"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "ptr", KeyWrap::Ptr);
  NODE_SET_PROTOTYPE_METHOD(tpl, "length", KeyWrap::Length);
  NODE_SET_PROTOTYPE_METHOD(tpl, "id", KeyWrap::Id);

  constructor = Persistent<Function>::New(tpl->GetFunction());
}

/**
 * KeyWrap クラスのインスタンスを生成します。
 *
 * args[0] に、AgentWrap のオブジェクトが指定されて呼び出されることを想定しています。
 * 
 */
Handle<Value> KeyWrap::New(const Arguments& args) {
  HandleScope scope;

  AgentWrap *agent = ObjectWrap::Unwrap<AgentWrap>(args[0]->ToObject());
  marisa::Key key = agent->agent().key();
  KeyWrap *inst = new KeyWrap(key);
  inst->Wrap(args.This());

  return args.This();
}

/**
 * Agent (AgentWrap) オブジェクトをもとに KeyWrap オブジェクトを生成します。
 */
Handle<Value> KeyWrap::NewInstanceFromAgent(Local<Object>& agent) {
  HandleScope scope;
  
  const int argc = 1;
  Handle<Value> argv[argc];
  argv[0] = agent;

  Local<Object> result = constructor->NewInstance(argc, argv);
  
  return scope.Close(result);
}

Handle<Value> KeyWrap::Ptr(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    KeyWrap *inst = ObjectWrap::Unwrap<KeyWrap>(args.This());
    const char *result = inst->key_.ptr();

    return scope.Close(String::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> KeyWrap::Length(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    KeyWrap *inst = ObjectWrap::Unwrap<KeyWrap>(args.This());
    int result = inst->key_.length();

    return scope.Close(Integer::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> KeyWrap::Id(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    KeyWrap *inst = ObjectWrap::Unwrap<KeyWrap>(args.This());
    int result = (int)inst->key_.id();

    return scope.Close(Integer::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}
