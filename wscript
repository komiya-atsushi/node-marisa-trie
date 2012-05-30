# -*- mode: Python -*-

srcdir = '.'
blddir = 'build'
VERSION = '0.0.1'

def set_options(opt):
  opt.tool_options('compiler_cxx')

def configure(conf):
  conf.check_tool('compiler_cxx')
  conf.check_tool('node_addon')

  conf.check_cxx(cxxflags = '-g')
  conf.check_cxx(cxxflags = '-Wall')

  conf.check(lib = 'marisa', libpath = [ '/usr/lib', '/usr/local/lib' ], uselib_store = 'marisa')

def build(bld):
  obj = bld.new_task_gen('cxx', 'shlib', 'node_addon')
  obj.target = 'marisa'
  obj.source = [
    'src/node-marisa.cc'
    , 'src/key.cc'
    , 'src/query.cc'
    , 'src/agent.cc'
    , 'src/keyset.cc'
    , 'src/trie.cc'
  ]
  obj.uselib = 'marisa'
