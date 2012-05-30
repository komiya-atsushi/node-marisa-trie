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