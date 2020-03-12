# kawpow-light-verifier

NOT YET FUNCTIONAL - DO NOT USE

This is a repository for the KAWPOW hashing algorithm that is used by Ravencoin beginning April 2020. It is not a full KAWPOW
validator and should not be relied upon to validate hashes from miners. It is to be used for local test validation and things
like that.

For nodejs, you should be able to do ``npm install https://github.com/traysi/kawpow-light-verifier/``

** INSTALLATION INSTRUCTIONS

Setup your nodejs environment first (I recommend nvm in your home directory) and then install node-gyp globally like:

$ npm install -g node-gyp

After that, you can build this module by:

$ git clone https://github.com/traysi/kawpow-light-verifier

$ cd kawpow-light-verifier

$ npm update

$ node-gyp rebuild

Then test it with:

$ node index.js
