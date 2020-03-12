{
    "targets": [
        {
            "target_name": "kawpow-light-verifier",
            "sources": [
                "light_verify.cc",
                "ethash/ethash.h",
                "ethash/ethash.hpp",
                "ethash/hash_types.h",
                "ethash/hash_types.hpp",
                "ethash/keccak.h",
                "ethash/keccak.hpp",
                "ethash/progpow.hpp",
                "ethash/version.h",
                "ethash/bit_manipulation.h",
                "ethash/builtins.h",
                "ethash/endianness.hpp",
                "ethash/ethash.cpp",
                "ethash/ethash-internal.hpp",
                "ethash/kiss99.hpp",
                "ethash/managed.cpp",
                "ethash/primes.c",
                "ethash/primes.h",
                "ethash/progpow.cpp",
                "ethash/keccak.c",
                "ethash/keccakf1600.c",
                "ethash/keccakf800.c",
                "ethash/attributes.h",
                "ethash/helpers.hpp",
                "ethash/progpow_test_vectors.hpp",
            ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")",
                'ethash/',
            ],
            "cflags_cc": [
                "-std=c++11"
            ],
        }
    ]
}



