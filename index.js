
var reverseBuffer = function(buff){
    var reversed = Buffer.alloc(buff.length);
    for (var i = buff.length - 1; i >= 0; i--)
        reversed[buff.length - i - 1] = buff[i];
    return reversed;
};


var lv = require('./build/Release/kawpow-light-verifier.node');

var header_hash = Buffer.from('597e1f24c4697b54328c6e4df53f333a48d585c2af69d45ce7e1c495d63e79ea','utf8');
var mix_hash = Buffer.from('8cd1a52bf2c92e7c3e6defb192853fb2855f9cc35be985c24c7d509b4b4518a0','utf8');
var str_nonce = Buffer.from('0e05f538571ab3f6','utf8'); // 1010483313742885878
var boundary = Buffer.from('0009f91f00000000000000000000000000000000000000000000000000000000','utf8');

// digest should be 000000191a87230fb4c4210a859449307fbd286cdbd5bffcd46a380008ac91a2

let out = lv.node_light_verify(header_hash, mix_hash, str_nonce, boundary);

console.log("digest = " + out.toString('hex'));




