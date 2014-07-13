#include "keyset_wrapper.h"

using namespace v8;
using namespace node;

Persistent<Function> KeysetWrap::constructor;

Handle<Value> CreateKeyset(const Arguments& args) {
  HandleScope scope;
  return scope.Close(KeysetWrap::NewInstance(args));
}

void KeysetWrap::Init(Handle<Object> target) {
  HandleScope scope;

  Local<FunctionTemplate> tpl = FunctionTemplate::New(KeysetWrap::New);
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(String::NewSymbol("Keyset"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "push_back", KeysetWrap::PushBack);
  NODE_SET_PROTOTYPE_METHOD(tpl, "pushBack", KeysetWrap::PushBack);
  NODE_SET_PROTOTYPE_METHOD(tpl, "num_keys", KeysetWrap::NumKeys);
  NODE_SET_PROTOTYPE_METHOD(tpl, "numKeys", KeysetWrap::NumKeys);
  NODE_SET_PROTOTYPE_METHOD(tpl, "empty", KeysetWrap::Empty);
  NODE_SET_PROTOTYPE_METHOD(tpl, "size", KeysetWrap::Size);
  NODE_SET_PROTOTYPE_METHOD(tpl, "total_length", KeysetWrap::TotalLength);
  NODE_SET_PROTOTYPE_METHOD(tpl, "totalLength", KeysetWrap::TotalLength);
  NODE_SET_PROTOTYPE_METHOD(tpl, "reset", KeysetWrap::Reset);
  NODE_SET_PROTOTYPE_METHOD(tpl, "clear", KeysetWrap::Clear);
  NODE_SET_PROTOTYPE_METHOD(tpl, "swap", KeysetWrap::Swap);

  constructor = Persistent<Function>::New(tpl->GetFunction());
  target->Set(String::NewSymbol("createKeyset"), FunctionTemplate::New(CreateKeyset)->GetFunction());
}

Handle<Value> KeysetWrap::New(const Arguments& args) {
  HandleScope scope;

  KeysetWrap *inst = new KeysetWrap();
  inst->Wrap(args.This());

  return args.This();
}

Handle<Value> KeysetWrap::NewInstance(const Arguments& args) {
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

Handle<Value> KeysetWrap::PushBack(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 1 && IS_OBJECT(0, KeyWrap)) {
    KeysetWrap *inst = ObjectWrap::Unwrap<KeysetWrap>(args.This());
    KeyWrap *arg0 = ObjectWrap::Unwrap<KeyWrap>(args[0]->ToObject());
    return KeysetWrap::PushBack0(scope, inst, arg0);
  }

  if (args.Length() == 2 && IS_OBJECT(0, KeyWrap) && IS_INT32(1)) {
    KeysetWrap *inst = ObjectWrap::Unwrap<KeysetWrap>(args.This());
    KeyWrap *arg0 = ObjectWrap::Unwrap<KeyWrap>(args[0]->ToObject());
    int32_t arg1 = args[1]->Int32Value();
    return KeysetWrap::PushBack1(scope, inst, arg0, arg1);
  }

  if (args.Length() == 1 && IS_STRING(0)) {
    KeysetWrap *inst = ObjectWrap::Unwrap<KeysetWrap>(args.This());
    String::Utf8Value arg0(args[0]->ToString());
    return KeysetWrap::PushBack2(scope, inst, arg0);
  }

  if (args.Length() == 3 && IS_STRING(0) && IS_INT32(1) && IS_NUMBER(2)) {
    KeysetWrap *inst = ObjectWrap::Unwrap<KeysetWrap>(args.This());
    String::Utf8Value arg0(args[0]->ToString());
    int32_t arg1 = args[1]->Int32Value();
    double arg2 = args[2]->NumberValue();
    return KeysetWrap::PushBack3(scope, inst, arg0, arg1, arg2);
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> KeysetWrap::PushBack0(HandleScope& scope, KeysetWrap *inst, KeyWrap *arg0) {
  inst->keyset_.push_back(arg0->key());
  return Undefined();
}

Handle<Value> KeysetWrap::PushBack1(HandleScope& scope, KeysetWrap *inst, KeyWrap *arg0, int32_t arg1) {
  inst->keyset_.push_back(arg0->key(), (char)arg1);
  return Undefined();
}

Handle<Value> KeysetWrap::PushBack2(HandleScope& scope, KeysetWrap *inst, String::Utf8Value& arg0) {
  inst->keyset_.push_back(*arg0);
  return Undefined();
}

Handle<Value> KeysetWrap::PushBack3(HandleScope& scope, KeysetWrap *inst, String::Utf8Value& arg0, int32_t arg1, double arg2) {
  inst->keyset_.push_back(*arg0, (std::size_t)arg1, (float)arg2);
  return Undefined();
}

Handle<Value> KeysetWrap::NumKeys(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    KeysetWrap *inst = ObjectWrap::Unwrap<KeysetWrap>(args.This());
    int result = inst->keyset_.num_keys();

    return scope.Close(Integer::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> KeysetWrap::Empty(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    KeysetWrap *inst = ObjectWrap::Unwrap<KeysetWrap>(args.This());
    bool result = inst->keyset_.empty();

    return scope.Close(Boolean::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> KeysetWrap::Size(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    KeysetWrap *inst = ObjectWrap::Unwrap<KeysetWrap>(args.This());
    int result = inst->keyset_.size();

    return scope.Close(Integer::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> KeysetWrap::TotalLength(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    KeysetWrap *inst = ObjectWrap::Unwrap<KeysetWrap>(args.This());
    int result = inst->keyset_.total_length();

    return scope.Close(Integer::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> KeysetWrap::Reset(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    KeysetWrap *inst = ObjectWrap::Unwrap<KeysetWrap>(args.This());
    inst->keyset_.reset();

    return Undefined();
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> KeysetWrap::Clear(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    KeysetWrap *inst = ObjectWrap::Unwrap<KeysetWrap>(args.This());
    inst->keyset_.clear();

    return Undefined();
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> KeysetWrap::Swap(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 1 && IS_OBJECT(0, KeysetWrap)) {
    KeysetWrap *inst = ObjectWrap::Unwrap<KeysetWrap>(args.This());
    KeysetWrap *arg0 = ObjectWrap::Unwrap<KeysetWrap>(args[0]->ToObject());
    inst->keyset_.swap(arg0->keyset_);

    return Undefined();
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

