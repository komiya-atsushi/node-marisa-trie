node-marisa-trie - marisa-trie for Node.js
================

簡潔データ構造を利用した trie のイケてる実装 marisa-trie を、Node.js から使えるようにするためのモジュールです。Node.js v0.6 以降で利用できます。

## Requirements

 * marisa-trie ( http://code.google.com/p/marisa-trie/ )

## Installation

    $ npm install node-marisa-trie

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

## License (MIT License)

Copyright (C) 2012 KOMIYA Atsushi

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## TODO

 * テストコードを記述する。
 * 未実装の API を実装する。
 * 使い方や API ドキュメントを書く・充実させる。
 * ドキュメントを英語化する。

など。
