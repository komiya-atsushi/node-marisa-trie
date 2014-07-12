target=./build/Release/node-marisa-trie.node

all: $(target)

build/:
	node-gyp configure

$(target): build/ src/*.cc src/*.h
	node-gyp build

clean:
	rm -rf build

test: $(target)
	npm test

