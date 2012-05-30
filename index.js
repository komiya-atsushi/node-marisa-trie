var marisa = require('./build/Release/marisa');

module.exports.createKeyset = function() {
    return marisa.createKeyset();
};

module.exports.createTrie = function() {
    return marisa.createTrie();
};

module.exports.createAgent = function() {
    return marisa.createAgent();
};