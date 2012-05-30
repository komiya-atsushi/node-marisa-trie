#include "query.h"
#include "agent.h"

using namespace v8;
using namespace node;

Persistent<Function> QueryWrap::constructor;

void QueryWrap::Init(Handle<Object> target) {
  HandleScope scope;

  Local<FunctionTemplate> tpl = FunctionTemplate::New(QueryWrap::New);
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(String::NewSymbol("Query"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "ptr", QueryWrap::Ptr);
  NODE_SET_PROTOTYPE_METHOD(tpl, "length", QueryWrap::Length);
  NODE_SET_PROTOTYPE_METHOD(tpl, "id", QueryWrap::Id);

  constructor = Persistent<Function>::New(tpl->GetFunction());
}

/**
 * QueryWrap クラスのインスタンスを生成します。
 *
 * args[0] に、AgentWrap のオブジェクトが指定されて呼び出されることを想定しています。
 */
Handle<Value> QueryWrap::New(const Arguments& args) {
  HandleScope scope;

  AgentWrap *agent = ObjectWrap::Unwrap<AgentWrap>(args[0]->ToObject());
  marisa::Query query = agent->agent().query();
  QueryWrap *inst = new QueryWrap(query);
  inst->Wrap(args.This());

  return args.This();
}

/**
 * Agent (AgentWrap) オブジェクトをもとに QueryWrap オブジェクトを生成します。
 */
Handle<Value> QueryWrap::NewInstanceFromAgent(Local<Object>& agent) {
  HandleScope scope;

  const int argc = 1;
  Handle<Value> argv[argc];
  argv[0] = agent;
  
  Local<Object> result = constructor->NewInstance(argc, argv);

  return scope.Close(result);
}

Handle<Value> QueryWrap::Ptr(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    QueryWrap *inst = ObjectWrap::Unwrap<QueryWrap>(args.This());
    const char *result = inst->query_.ptr();

    return scope.Close(String::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> QueryWrap::Length(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    QueryWrap *inst = ObjectWrap::Unwrap<QueryWrap>(args.This());
    int result = inst->query_.length();

    return scope.Close(Integer::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> QueryWrap::Id(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    QueryWrap *inst = ObjectWrap::Unwrap<QueryWrap>(args.This());
    int result = inst->query_.id();

    return scope.Close(Integer::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

