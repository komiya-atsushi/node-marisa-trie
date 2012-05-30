#include "trie.h"
#include "keyset.h"
#include "agent.h"

using namespace v8;
using namespace node;

Persistent<Function> TrieWrap::constructor;

Handle<Value> CreateTrie(const Arguments& args) {
  HandleScope scope;
  return scope.Close(TrieWrap::NewInstance(args));
}

void TrieWrap::Init(Handle<Object> target) {
  HandleScope scope;

  Local<FunctionTemplate> tpl = FunctionTemplate::New(TrieWrap::New);
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(String::NewSymbol("Trie"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "build", TrieWrap::Build);
  NODE_SET_PROTOTYPE_METHOD(tpl, "mmap", TrieWrap::Mmap);
  NODE_SET_PROTOTYPE_METHOD(tpl, "load", TrieWrap::Load);
  NODE_SET_PROTOTYPE_METHOD(tpl, "save", TrieWrap::Save);
  NODE_SET_PROTOTYPE_METHOD(tpl, "lookup", TrieWrap::Lookup);
  NODE_SET_PROTOTYPE_METHOD(tpl, "reverse_lookup", TrieWrap::ReverseLookup);
  NODE_SET_PROTOTYPE_METHOD(tpl, "reverseLookup", TrieWrap::ReverseLookup);
  NODE_SET_PROTOTYPE_METHOD(tpl, "common_prefix_search", TrieWrap::CommonPrefixSearch);
  NODE_SET_PROTOTYPE_METHOD(tpl, "commonPrefixSearch", TrieWrap::CommonPrefixSearch);
  NODE_SET_PROTOTYPE_METHOD(tpl, "predictive_search", TrieWrap::PredictiveSearch);
  NODE_SET_PROTOTYPE_METHOD(tpl, "predictiveSearch", TrieWrap::PredictiveSearch);
  NODE_SET_PROTOTYPE_METHOD(tpl, "num_tries", TrieWrap::NumTries);
  NODE_SET_PROTOTYPE_METHOD(tpl, "numTries", TrieWrap::NumTries);
  NODE_SET_PROTOTYPE_METHOD(tpl, "num_keys", TrieWrap::NumKeys);
  NODE_SET_PROTOTYPE_METHOD(tpl, "numKeys", TrieWrap::NumKeys);
  NODE_SET_PROTOTYPE_METHOD(tpl, "num_nodes", TrieWrap::NumNodes);
  NODE_SET_PROTOTYPE_METHOD(tpl, "numNodes", TrieWrap::NumNodes);
  NODE_SET_PROTOTYPE_METHOD(tpl, "empty", TrieWrap::Empty);
  NODE_SET_PROTOTYPE_METHOD(tpl, "size", TrieWrap::Size);
  NODE_SET_PROTOTYPE_METHOD(tpl, "io_size", TrieWrap::IoSize);
  NODE_SET_PROTOTYPE_METHOD(tpl, "ioSize", TrieWrap::IoSize);
  NODE_SET_PROTOTYPE_METHOD(tpl, "clear", TrieWrap::Clear);
  NODE_SET_PROTOTYPE_METHOD(tpl, "swap", TrieWrap::Swap);

  constructor = Persistent<Function>::New(tpl->GetFunction());
  target->Set(String::NewSymbol("createTrie"), FunctionTemplate::New(CreateTrie)->GetFunction());
}

Handle<Value> TrieWrap::New(const Arguments& args) {
  HandleScope scope;

  TrieWrap *inst = new TrieWrap();
  inst->Wrap(args.This());

  return args.This();
}

Handle<Value> TrieWrap::NewInstance(const Arguments& args) {
  HandleScope scope;

  const int argc = args.Length();
  Handle<Value> argv[argc];
  for (int i = 0; i < argc; i++) {
    argv[i] = args[i];
  }
  
  Local<Object> result = constructor->NewInstance(argc, argv);

  return scope.Close(result);
}

Handle<Value> TrieWrap::Build(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 1 && IS_OBJECT(0, KeysetWrap)) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    KeysetWrap *arg0 = ObjectWrap::Unwrap<KeysetWrap>(args[0]->ToObject());
    inst->trie_.build(arg0->keyset());

    return Undefined();
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::Mmap(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 1 && IS_STRING(0)) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    String::Utf8Value arg0(args[0]->ToString());
    inst->trie_.mmap(*arg0);

    return Undefined();
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::Load(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 1 && IS_STRING(0)) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    String::Utf8Value arg0(args[0]->ToString());
    inst->trie_.load(*arg0);

    return Undefined();
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::Save(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 1 && IS_STRING(0)) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    String::Utf8Value arg0(args[0]->ToString());
    inst->trie_.save(*arg0);

    return Undefined();
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::Lookup(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 1 && IS_OBJECT(0, AgentWrap)) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    AgentWrap *arg0 = ObjectWrap::Unwrap<AgentWrap>(args[0]->ToObject());
    bool result = inst->trie_.lookup(arg0->agent());

    return scope.Close(Boolean::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::ReverseLookup(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 1 && IS_OBJECT(0, AgentWrap)) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    AgentWrap *arg0 = ObjectWrap::Unwrap<AgentWrap>(args[0]->ToObject());
    inst->trie_.reverse_lookup(arg0->agent());

    return Undefined();
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::CommonPrefixSearch(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 1 && IS_OBJECT(0, AgentWrap)) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    AgentWrap *arg0 = ObjectWrap::Unwrap<AgentWrap>(args[0]->ToObject());
    bool result = inst->trie_.common_prefix_search(arg0->agent());

    return scope.Close(Boolean::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::PredictiveSearch(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 1 && IS_OBJECT(0, AgentWrap)) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    AgentWrap *arg0 = ObjectWrap::Unwrap<AgentWrap>(args[0]->ToObject());
    bool result = inst->trie_.predictive_search(arg0->agent());

    return scope.Close(Boolean::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::NumTries(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    int result = inst->trie_.num_tries();

    return scope.Close(Integer::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::NumKeys(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    int result = inst->trie_.num_keys();

    return scope.Close(Integer::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::NumNodes(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    int result = inst->trie_.num_nodes();

    return scope.Close(Integer::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::Empty(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    bool result = inst->trie_.empty();

    return scope.Close(Boolean::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::Size(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    int result = inst->trie_.size();

    return scope.Close(Integer::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::IoSize(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    int result = inst->trie_.io_size();

    return scope.Close(Integer::New(result));
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::Clear(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    inst->trie_.clear();

    return Undefined();
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

Handle<Value> TrieWrap::Swap(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 1 && IS_OBJECT(0, TrieWrap)) {
    TrieWrap *inst = ObjectWrap::Unwrap<TrieWrap>(args.This());
    TrieWrap *arg0 = ObjectWrap::Unwrap<TrieWrap>(args[0]->ToObject());
    inst->trie_.swap(arg0->trie_);

    return Undefined();
  }

  return ThrowException(Exception::Error(String::New("Wrong argument(s).")));
}

