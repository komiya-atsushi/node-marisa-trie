#define BUILDING_NODE_EXTENSION

#include <node.h>

#include "node-marisa.h"

#include "key.h"
#include "query.h"
#include "agent_wrapper.h"
#include "keyset_wrapper.h"
#include "trie_wrapper.h"

using namespace v8;

void InitNodeMarisa(Handle<Object> target) {
  KeyWrap::Init(target);
  QueryWrap::Init(target);
  AgentWrap::Init(target);
  KeysetWrap::Init(target);
  TrieWrap::Init(target);
}

NODE_MODULE(marisa, InitNodeMarisa)

