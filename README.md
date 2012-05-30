node-marisa-trie
================

marisa-trie for Node.js

## Requirements

 * marisa-trie ( http://code.google.com/p/marisa-trie/ )

## Installation

    npm install node-marisa-trie

## Usage

```JavaScript
var marisa = require('node-marisa-trie');

var keyset = marisa.createKeyset();
keyset.push_back("a");
keyset.push_back("app");
keyset.push_back("apple");

var trie = marisa.createTrie();
trie.build(keyset);

var agent = marisa.createAgent();
agent.set_query("apple");
while (trie.common_prefix_search(agent)) {
    var key = agent.key();
    console.log(key.ptr().substring(0, key.length()));
}
```

## TODO

 * テストコードを記述する。
 * 未実装の API を実装する。
 * 使い方や API ドキュメントを書く・充実させる。
 * ドキュメントを英語化する。
 * node-gyp でのビルドに対応する。

など。