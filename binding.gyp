{
  'targets': [
    {
      'target_name': 'marisa',
      'sources': [
        'src/node-marisa.cc',
        'src/key.cc',
        'src/query.cc',
        'src/agent.cc',
        'src/keyset.cc',
        'src/trie.cc',
      ],
      'conditions': [
        ['OS == "win"', {
          'libraries': [
            '-llibmarisa.lib',
          ],
          'include_dirs': [
            '$(LIBMARISA)/include',
          ],
          'msvs_settings': {
            'VCLinkerTool': {
              'AdditionalLibraryDirectories': '$(LIBMARISA)/lib',
            },
          },
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
