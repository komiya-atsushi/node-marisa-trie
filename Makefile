target=./build/Release/node-marisa-trie.node

all: $(target)

build/:
	node-waf configure

$(target): build/ src/*.cc src/*.h
	node-waf build

clean:
	rm -rf build

test: $(target)
	npm test

