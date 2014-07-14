{
  'targets': [
    {
      'target_name': 'marisa',
      'sources': [
        'src/node-marisa.cc',
        'src/key.cc',
        'src/query.cc',
        'src/agent_wrapper.cc',
        'src/keyset_wrapper.cc',
        'src/trie_wrapper.cc',
      ],
      'conditions': [
        ['OS == "win"', {
          'dependencies': [
            'libmarisa.gyp:libmarisa',
          ],
          'include_dirs': [
            'libmarisa',
          ],
        }],
        ['OS == "mac"', {
          'libraries': [
            '-lmarisa',
            '-L/usr/local/lib',
          ],
          'xcode_settings': {
            'MACOSX_DEPLOYMENT_TARGET': '10.7',
            'OTHER_CPLUSPLUSFLAGS': [
              '-stdlib=libc++',
              '-I/usr/local/include',
            ],
          },
        }],
        ['OS == "linux"', {
          'libraries': [
            '-lmarisa',
          ],
          'include_dirs': [
            '/usr/lib',
            '/usr/local/lib',
          ],
        }],
      ],
    },
  ],
}
