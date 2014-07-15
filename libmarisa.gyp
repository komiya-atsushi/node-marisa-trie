{
  'targets': [
    {
      'target_name': 'libmarisa',
      'product_prefix': 'lib',
      'type': 'static_library',
      'sources': [
        'libmarisa/marisa/agent.cc',
        'libmarisa/marisa/grimoire/vector/bit-vector.cc',
        'libmarisa/marisa/keyset.cc',
        'libmarisa/marisa/grimoire/trie/louds-trie.cc',
        'libmarisa/marisa/grimoire/io/mapper.cc',
        'libmarisa/marisa/grimoire/io/reader.cc',
        'libmarisa/marisa/grimoire/trie/tail.cc',
        'libmarisa/marisa/trie.cc',
        'libmarisa/marisa/grimoire/io/writer.cc',
      ],
      'include_dirs': [
        'libmarisa',
      ],
      'conditions': [
        ['OS == "linux"', {
          'cflags!': [ '-fno-exceptions' ],
          'cflags_cc!': [ '-fno-exceptions' ],
        }],
      ],
    },
  ],
}
