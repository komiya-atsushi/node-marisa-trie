// -*- mode: C++ -*-

#ifndef _TRIE_H__
#define _TRIE_H__

#include "node-marisa.h"

class TrieWrap : node::ObjectWrap {
public:
  static void Init(v8::Handle<v8::Object> target);
  static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);
  marisa::Trie& trie() { return trie_; }

private:
  TrieWrap() {}
  ~TrieWrap() {}

  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Handle<v8::Value> Build(const v8::Arguments& args);
  static v8::Handle<v8::Value> Mmap(const v8::Arguments& args);
  static v8::Handle<v8::Value> Map(const v8::Arguments& args);
  static v8::Handle<v8::Value> Load(const v8::Arguments& args);
  static v8::Handle<v8::Value> Save(const v8::Arguments& args);
  static v8::Handle<v8::Value> Lookup(const v8::Arguments& args);
  static v8::Handle<v8::Value> ReverseLookup(const v8::Arguments& args);
  static v8::Handle<v8::Value> CommonPrefixSearch(const v8::Arguments& args);
  static v8::Handle<v8::Value> PredictiveSearch(const v8::Arguments& args);
  static v8::Handle<v8::Value> NumTries(const v8::Arguments& args);
  static v8::Handle<v8::Value> NumKeys(const v8::Arguments& args);
  static v8::Handle<v8::Value> NumNodes(const v8::Arguments& args);
  static v8::Handle<v8::Value> Empty(const v8::Arguments& args);
  static v8::Handle<v8::Value> Size(const v8::Arguments& args);
  static v8::Handle<v8::Value> IoSize(const v8::Arguments& args);
  static v8::Handle<v8::Value> Clear(const v8::Arguments& args);
  static v8::Handle<v8::Value> Swap(const v8::Arguments& args);

  static v8::Persistent<v8::Function> constructor;
  marisa::Trie trie_;
};

#endif
