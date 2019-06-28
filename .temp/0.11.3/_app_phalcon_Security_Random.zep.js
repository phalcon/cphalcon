[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Security\/Random.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Security",
        "file": "\/app\/phalcon\/Security\/Random.zep",
        "line": 84,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Security\\Random\n *\n * Secure random number generator class.\n *\n * Provides secure random number generator which is suitable for generating\n * session key in HTTP cookies, etc.\n *\n * It supports following secure random number generators:\n *\n * - random_bytes (PHP 7)\n * - libsodium\n * - openssl, libressl\n * - \/dev\/urandom\n *\n * `Phalcon\\Security\\Random` could be mainly useful for:\n *\n * - Key generation (e.g. generation of complicated keys)\n * - Generating random passwords for new user accounts\n * - Encryption systems\n *\n *```php\n * $random = new \\Phalcon\\Security\\Random();\n *\n * \/\/ Random binary string\n * $bytes = $random->bytes();\n *\n * \/\/ Random hex string\n * echo $random->hex(10); \/\/ a29f470508d5ccb8e289\n * echo $random->hex(10); \/\/ 533c2f08d5eee750e64a\n * echo $random->hex(11); \/\/ f362ef96cb9ffef150c9cd\n * echo $random->hex(12); \/\/ 95469d667475125208be45c4\n * echo $random->hex(13); \/\/ 05475e8af4a34f8f743ab48761\n *\n * \/\/ Random base62 string\n * echo $random->base62(); \/\/ z0RkwHfh8ErDM1xw\n *\n * \/\/ Random base64 string\n * echo $random->base64(12); \/\/ XfIN81jGGuKkcE1E\n * echo $random->base64(12); \/\/ 3rcq39QzGK9fUqh8\n * echo $random->base64();   \/\/ DRcfbngL\/iOo9hGGvy1TcQ==\n * echo $random->base64(16); \/\/ SvdhPcIHDZFad838Bb0Swg==\n *\n * \/\/ Random URL-safe base64 string\n * echo $random->base64Safe();           \/\/ PcV6jGbJ6vfVw7hfKIFDGA\n * echo $random->base64Safe();           \/\/ GD8JojhzSTrqX7Q8J6uug\n * echo $random->base64Safe(8);          \/\/ mGyy0evy3ok\n * echo $random->base64Safe(null, true); \/\/ DRrAgOFkS4rvRiVHFefcQ==\n *\n * \/\/ Random UUID\n * echo $random->uuid(); \/\/ db082997-2572-4e2c-a046-5eefe97b1235\n * echo $random->uuid(); \/\/ da2aa0e2-b4d0-4e3c-99f5-f5ef62c57fe2\n * echo $random->uuid(); \/\/ 75e6b628-c562-4117-bb76-61c4153455a9\n * echo $random->uuid(); \/\/ dc446df1-0848-4d05-b501-4af3c220c13d\n *\n * \/\/ Random number between 0 and $len\n * echo $random->number(256); \/\/ 84\n * echo $random->number(256); \/\/ 79\n * echo $random->number(100); \/\/ 29\n * echo $random->number(300); \/\/ 40\n *\n * \/\/ Random base58 string\n * echo $random->base58();   \/\/ 4kUgL2pdQMSCQtjE\n * echo $random->base58();   \/\/ Umjxqf7ZPwh765yR\n * echo $random->base58(24); \/\/ qoXcgmw4A9dys26HaNEdCRj9\n * echo $random->base58(7);  \/\/ 774SJD3vgP\n *```\n *\n * This class partially borrows SecureRandom library from Ruby\n *\n * @link http:\/\/ruby-doc.org\/stdlib-2.2.2\/libdoc\/securerandom\/rdoc\/SecureRandom.html\n *",
        "file": "\/app\/phalcon\/Security\/Random.zep",
        "line": 85,
        "char": 5
    },
    {
        "type": "class",
        "name": "Random",
        "abstract": 0,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "base58",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "len",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 107,
                                "char": 42
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 107,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 109,
                                    "char": 21
                                },
                                "name": "base",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 110,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 110,
                                        "char": 71
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "58",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 111,
                                            "char": 15
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 111,
                                        "char": 15
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "len",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 113,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 113,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 113,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 114,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a random base58 string\n     *\n     * If $len is not specified, 16 is assumed. It may be larger in future.\n     * The result may contain alphanumeric characters except 0, O, I and l.\n     *\n     * It is similar to `Phalcon\\Security\\Random::base64()` but has been\n     * modified to avoid both non-alphanumeric characters and letters which\n     * might look ambiguous when printed.\n     *\n     *```php\n     * $random = new \\Phalcon\\Security\\Random();\n     *\n     * echo $random->base58(); \/\/ 4kUgL2pdQMSCQtjE\n     *```\n     *\n     * @see    \\Phalcon\\Security\\Random:base64\n     * @link   https:\/\/en.wikipedia.org\/wiki\/Base58\n     * @throws Exception If secure random number generator is not available or unexpected partial read\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 108,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security\/Random.zep",
                        "line": 108,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security\/Random.zep",
                    "line": 107,
                    "last-line": 134,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "base62",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "len",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 135,
                                "char": 42
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 135,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 137,
                                    "char": 21
                                },
                                "name": "base",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 138,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 138,
                                        "char": 75
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "62",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 139,
                                            "char": 15
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 139,
                                        "char": 15
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "len",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 141,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 141,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 141,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 142,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a random base62 string\n     *\n     * If $len is not specified, 16 is assumed. It may be larger in future.\n     *\n     * It is similar to `Phalcon\\Security\\Random::base58()` but has been\n     * modified to provide the largest value that can safely be used in URLs\n     * without needing to take extra characters into consideration because it is\n     * [A-Za-z0-9].\n     *\n     *```php\n     * $random = new \\Phalcon\\Security\\Random();\n     *\n     * echo $random->base62(); \/\/ z0RkwHfh8ErDM1xw\n     *```\n     *\n     * @see    \\Phalcon\\Security\\Random:base58\n     * @throws Exception If secure random number generator is not available or unexpected partial read\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 136,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security\/Random.zep",
                        "line": 136,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security\/Random.zep",
                    "line": 135,
                    "last-line": 158,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "base64",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "len",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 159,
                                "char": 42
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 159,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "base64_encode",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 162,
                                                "char": 18
                                            },
                                            "name": "bytes",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "len",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 162,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 162,
                                                    "char": 28
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 163,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 163,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 163,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 164,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a random base64 string\n     *\n     * If $len is not specified, 16 is assumed. It may be larger in future.\n     * The length of the result string is usually greater of $len.\n     * Size formula: 4 * ($len \/ 3) rounded up to a multiple of 4.\n     *\n     *```php\n     * $random = new \\Phalcon\\Security\\Random();\n     *\n     * echo $random->base64(12); \/\/ 3rcq39QzGK9fUqh8\n     *```\n     *\n     * @throws Exception If secure random number generator is not available or unexpected partial read\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 160,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security\/Random.zep",
                        "line": 160,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security\/Random.zep",
                    "line": 159,
                    "last-line": 185,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "base64Safe",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "len",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 186,
                                "char": 46
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 186,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "padding",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 186,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 186,
                            "char": 68
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "s",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 188,
                                    "char": 14
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 190,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "s",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "base64_encode",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                    "line": 192,
                                                                    "char": 22
                                                                },
                                                                "name": "base64",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "len",
                                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                            "line": 192,
                                                                            "char": 33
                                                                        },
                                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                        "line": 192,
                                                                        "char": 33
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                "line": 193,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 193,
                                                            "char": 13
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 193,
                                                    "char": 14
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 193,
                                                "char": 14
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "+\/",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 194,
                                                    "char": 15
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 194,
                                                "char": 15
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "-_",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 196,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 196,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 196,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 196,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 198,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "s",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "preg_replace",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "#[^a-z0-9_=-]+#i",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 199,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 199,
                                                "char": 29
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 200,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 200,
                                                "char": 13
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "s",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 202,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 202,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 202,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 202,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 204,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "padding",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 204,
                                    "char": 21
                                },
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 204,
                                "char": 21
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "rtrim",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "s",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 205,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 205,
                                                "char": 27
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "=",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 205,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 205,
                                                "char": 30
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 205,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 206,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 208,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "s",
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 208,
                                "char": 17
                            },
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 209,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a random URL-safe base64 string\n     *\n     * If $len is not specified, 16 is assumed. It may be larger in future.\n     * The length of the result string is usually greater of $len.\n     *\n     * By default, padding is not generated because \"=\" may be used as a URL\n     * delimiter. The result may contain A-Z, a-z, 0-9, \"-\" and \"_\". \"=\" is also\n     * used if $padding is true. See RFC 3548 for the definition of URL-safe\n     * base64.\n     *\n     *```php\n     * $random = new \\Phalcon\\Security\\Random();\n     *\n     * echo $random->base64Safe(); \/\/ GD8JojhzSTrqX7Q8J6uug\n     *```\n     *\n     * @link https:\/\/www.ietf.org\/rfc\/rfc3548.txt\n     * @throws Exception If secure random number generator is not available or unexpected partial read\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 187,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security\/Random.zep",
                        "line": 187,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security\/Random.zep",
                    "line": 186,
                    "last-line": 229,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "bytes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "len",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "16",
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 230,
                                "char": 39
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 230,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "handle",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 232,
                                    "char": 19
                                },
                                {
                                    "variable": "ret",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 232,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 234,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "less-equal",
                                "left": {
                                    "type": "variable",
                                    "value": "len",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 234,
                                    "char": 16
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 234,
                                    "char": 20
                                },
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 234,
                                "char": 20
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "len",
                                            "expr": {
                                                "type": "int",
                                                "value": "16",
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 235,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 235,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 236,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 238,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "random_bytes",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 238,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 238,
                                        "char": 40
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 238,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "random_bytes",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "len",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 239,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 239,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 239,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 240,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 242,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "\\\\Sodium\\\\randombytes_buf",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 242,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 242,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 242,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "\\\\Sodium\\\\randombytes_buf",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "len",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 243,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 243,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 243,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 244,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 246,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "openssl_random_pseudo_bytes",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 246,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 246,
                                        "char": 55
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 246,
                                "char": 57
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "openssl_random_pseudo_bytes",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "len",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 247,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 247,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 247,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 248,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 250,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "handle",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 250,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 250,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 252,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "file_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "\/dev\/urandom",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 252,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 252,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 252,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handle",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "fopen",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "\/dev\/urandom",
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 253,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 253,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "rb",
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 253,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 253,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 253,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 253,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 254,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 256,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "variable",
                                        "value": "handle",
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 256,
                                        "char": 30
                                    },
                                    "right": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 256,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 256,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 256,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "No random device available",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 257,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 257,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 257,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 258,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 260,
                            "char": 30
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "stream_set_read_buffer",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handle",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 260,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 260,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 260,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 260,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 260,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 262,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ret",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "fread",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "handle",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 262,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 262,
                                                "char": 31
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "len",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 262,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 262,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 262,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 262,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 264,
                            "char": 14
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "fclose",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handle",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 264,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 264,
                                        "char": 22
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 264,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 266,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "fcall",
                                        "name": "strlen",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ret",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 266,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 266,
                                                "char": 31
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 266,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "len",
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 266,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 266,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 266,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Unexpected partial read from random device",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 269,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 269,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 269,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 270,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 272,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "ret",
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 272,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 273,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a random binary string\n     *\n     * The `Random::bytes` method returns a string and accepts as input an int\n     * representing the length in bytes to be returned.\n     *\n     * If $len is not specified, 16 is assumed. It may be larger in future.\n     * The result may contain any byte: \"x00\" - \"xFF\".\n     *\n     *```php\n     * $random = new \\Phalcon\\Security\\Random();\n     *\n     * $bytes = $random->bytes();\n     * var_dump(bin2hex($bytes));\n     * \/\/ Possible output: string(32) \"00f6c04b144b41fad6a59111c126e1ee\"\n     *```\n     *\n     * @throws Exception If secure random number generator is not available or unexpected partial read\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 231,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security\/Random.zep",
                        "line": 231,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security\/Random.zep",
                    "line": 230,
                    "last-line": 288,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hex",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "len",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 289,
                                "char": 39
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 289,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "array_shift",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "unpack",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "H*",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 293,
                                                        "char": 19
                                                    },
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 293,
                                                    "char": 19
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 294,
                                                            "char": 22
                                                        },
                                                        "name": "bytes",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "len",
                                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                    "line": 294,
                                                                    "char": 32
                                                                },
                                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                "line": 294,
                                                                "char": 32
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 295,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 295,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 296,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 296,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 296,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 297,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a random hex string\n     *\n     * If $len is not specified, 16 is assumed. It may be larger in future.\n     * The length of the result string is usually greater of $len.\n     *\n     *```php\n     * $random = new \\Phalcon\\Security\\Random();\n     *\n     * echo $random->hex(10); \/\/ a29f470508d5ccb8e289\n     *```\n     *\n     * @throws Exception If secure random number generator is not available or unexpected partial read\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 290,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security\/Random.zep",
                        "line": 290,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security\/Random.zep",
                    "line": 289,
                    "last-line": 310,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "number",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "len",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 311,
                            "char": 35
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "hex",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 313,
                                    "char": 16
                                },
                                {
                                    "variable": "mask",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 313,
                                    "char": 22
                                },
                                {
                                    "variable": "rnd",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 313,
                                    "char": 27
                                },
                                {
                                    "variable": "ret",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 313,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 314,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "bin",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 314,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 314,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 316,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "less-equal",
                                    "left": {
                                        "type": "variable",
                                        "value": "len",
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 316,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 316,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 316,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 316,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "Exception",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Require a positive integer > 0",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 317,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 317,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 317,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 318,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 320,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "random_int",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 320,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 320,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 320,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "random_int",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 321,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 321,
                                                "char": 32
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "len",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 321,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 321,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 321,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 322,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 324,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "\\\\Sodium\\\\randombytes_uniform",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 324,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 324,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 324,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "add",
                                        "left": {
                                            "type": "fcall",
                                            "name": "\\\\Sodium\\\\randombytes_uniform",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "len",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 329,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 329,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 329,
                                            "char": 55
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 329,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 329,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 330,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 332,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "hex",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "dechex",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "len",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 332,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 332,
                                                "char": 29
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 332,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 332,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 334,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "bitwise_and",
                                        "left": {
                                            "type": "fcall",
                                            "name": "strlen",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "hex",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 334,
                                                        "char": 23
                                                    },
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 334,
                                                    "char": 23
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 334,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 334,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 334,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 334,
                                    "char": 31
                                },
                                "right": {
                                    "type": "int",
                                    "value": "1",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 334,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 334,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "hex",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 335,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "hex",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 335,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 335,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 335,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 336,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 338,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "bin",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "pack",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "H*",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 338,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 338,
                                                "char": 26
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "hex",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 338,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 338,
                                                "char": 31
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 338,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 338,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 340,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mask",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "ord",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "bin",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 340,
                                                        "char": 27
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 340,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 340,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 340,
                                                "char": 30
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 340,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 340,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 341,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mask",
                                    "expr": {
                                        "type": "bitwise_or",
                                        "left": {
                                            "type": "variable",
                                            "value": "mask",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 341,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "list",
                                            "left": {
                                                "type": "bitwise_shiftright",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "mask",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 341,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 341,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 341,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 341,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 341,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 341,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 342,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mask",
                                    "expr": {
                                        "type": "bitwise_or",
                                        "left": {
                                            "type": "variable",
                                            "value": "mask",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 342,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "list",
                                            "left": {
                                                "type": "bitwise_shiftright",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "mask",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 342,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "2",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 342,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 342,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 342,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 342,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 342,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 343,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mask",
                                    "expr": {
                                        "type": "bitwise_or",
                                        "left": {
                                            "type": "variable",
                                            "value": "mask",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 343,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "list",
                                            "left": {
                                                "type": "bitwise_shiftright",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "mask",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 343,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "4",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 343,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 343,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 343,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 343,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 343,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 345,
                            "char": 10
                        },
                        {
                            "type": "do-while",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "variable",
                                    "value": "bin",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 356,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "rnd",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 356,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 356,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "rnd",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 346,
                                                    "char": 28
                                                },
                                                "name": "bytes",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "strlen",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "bin",
                                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                        "line": 346,
                                                                        "char": 45
                                                                    },
                                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                    "line": 346,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 346,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 346,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 346,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 346,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 348,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "rnd",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "substr_replace",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "rnd",
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 349,
                                                            "char": 20
                                                        },
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 349,
                                                        "char": 20
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "chr",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "bitwise_and",
                                                                        "left": {
                                                                            "type": "fcall",
                                                                            "name": "ord",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "fcall",
                                                                                        "name": "substr",
                                                                                        "call-type": 1,
                                                                                        "parameters": [
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "variable",
                                                                                                    "value": "rnd",
                                                                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                                                    "line": 351,
                                                                                                    "char": 35
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                                                "line": 351,
                                                                                                "char": 35
                                                                                            },
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "int",
                                                                                                    "value": "0",
                                                                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                                                    "line": 351,
                                                                                                    "char": 38
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                                                "line": 351,
                                                                                                "char": 38
                                                                                            },
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "int",
                                                                                                    "value": "1",
                                                                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                                                    "line": 351,
                                                                                                    "char": 41
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                                                "line": 351,
                                                                                                "char": 41
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                                        "line": 351,
                                                                                        "char": 42
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                                    "line": 351,
                                                                                    "char": 42
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                            "line": 351,
                                                                            "char": 44
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "mask",
                                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                            "line": 352,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                        "line": 352,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                    "line": 352,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 352,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 352,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 353,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 353,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 355,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 355,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 355,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 355,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 356,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 358,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ret",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "unpack",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "H*",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 358,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 358,
                                                "char": 28
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "rnd",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 358,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 358,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 358,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 358,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 360,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "hexdec",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "array_shift",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "ret",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 361,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 361,
                                                    "char": 28
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 362,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 362,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 362,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 363,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a random number between 0 and $len\n     *\n     * Returns an integer: 0 <= result <= $len.\n     *\n     *```php\n     * $random = new \\Phalcon\\Security\\Random();\n     *\n     * echo $random->number(16); \/\/ 8\n     *```\n     * @throws Exception If secure random number generator is not available, unexpected partial read or $len <= 0\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 312,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security\/Random.zep",
                        "line": 312,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security\/Random.zep",
                    "line": 311,
                    "last-line": 386,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "uuid",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "ary",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 389,
                                    "char": 16
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 391,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ary",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_values",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "unpack",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "N1a\/n1b\/n1c\/n1d\/n1e\/N1f",
                                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                "line": 393,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 393,
                                                            "char": 40
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                    "line": 394,
                                                                    "char": 22
                                                                },
                                                                "name": "bytes",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "int",
                                                                            "value": "16",
                                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                            "line": 394,
                                                                            "char": 31
                                                                        },
                                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                        "line": 394,
                                                                        "char": 31
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                "line": 395,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 395,
                                                            "char": 13
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 396,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 396,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 396,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 396,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 398,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "ary",
                                    "index-expr": [
                                        {
                                            "type": "int",
                                            "value": "2",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 398,
                                            "char": 18
                                        }
                                    ],
                                    "expr": {
                                        "type": "bitwise_or",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "bitwise_and",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "ary",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 398,
                                                        "char": 26
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "2",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 398,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 398,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0x0fff",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 398,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 398,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 398,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0x4000",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 398,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 398,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 398,
                                    "char": 48
                                },
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "ary",
                                    "index-expr": [
                                        {
                                            "type": "int",
                                            "value": "3",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 399,
                                            "char": 18
                                        }
                                    ],
                                    "expr": {
                                        "type": "bitwise_or",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "bitwise_and",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "ary",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 399,
                                                        "char": 26
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "3",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 399,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 399,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0x3fff",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 399,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 399,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 399,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0x8000",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 399,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 399,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 399,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 401,
                            "char": 21
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "array_unshift",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "ary",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 402,
                                            "char": 16
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 402,
                                        "char": 16
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "%08x-%04x-%04x-%04x-%04x%08x",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 404,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 404,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 404,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 406,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "call_user_func_array",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "sprintf",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 406,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 406,
                                        "char": 44
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "ary",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 406,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 406,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 406,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 407,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a v4 random UUID (Universally Unique IDentifier)\n     *\n     * The version 4 UUID is purely random (except the version). It doesn't\n     * contain meaningful information such as MAC address, time, etc. See RFC\n     * 4122 for details of UUID.\n     *\n     * This algorithm sets the version number (4 bits) as well as two reserved\n     * bits. All other bits (the remaining 122 bits) are set using a random or\n     * pseudorandom data source. Version 4 UUIDs have the form\n     * xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx where x is any hexadecimal digit and\n     * y is one of 8, 9, A, or B (e.g., f47ac10b-58cc-4372-a567-0e02b2c3d479).\n     *\n     *```php\n     * $random = new \\Phalcon\\Security\\Random();\n     *\n     * echo $random->uuid(); \/\/ 1378c906-64bb-4f81-a8d6-4ae1bfcdec22\n     *```\n     *\n     * @link https:\/\/www.ietf.org\/rfc\/rfc4122.txt\n     * @throws Exception If secure random number generator is not available or unexpected partial read\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 388,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security\/Random.zep",
                        "line": 388,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security\/Random.zep",
                    "line": 387,
                    "last-line": 417,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "base",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "alphabet",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 418,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "base",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 418,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "n",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 418,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 418,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "bytes",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 420,
                                    "char": 18
                                },
                                {
                                    "variable": "idx",
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 420,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 421,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "byteString",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 421,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 421,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 423,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "bytes",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "unpack",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "C*",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 424,
                                                    "char": 15
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 424,
                                                "char": 15
                                            },
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 425,
                                                        "char": 18
                                                    },
                                                    "name": "bytes",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "n",
                                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                "line": 425,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 425,
                                                            "char": 26
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 426,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 426,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 426,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 426,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 428,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "bytes",
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 428,
                                "char": 26
                            },
                            "value": "idx",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "idx",
                                            "expr": {
                                                "type": "mod",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "idx",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 429,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "64",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 429,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 429,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 429,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 431,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater-equal",
                                        "left": {
                                            "type": "variable",
                                            "value": "idx",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 431,
                                            "char": 20
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "base",
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 431,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                        "line": 431,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "idx",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                                            "line": 432,
                                                            "char": 32
                                                        },
                                                        "name": "number",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "sub",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "base",
                                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                        "line": 432,
                                                                        "char": 45
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                        "line": 432,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                    "line": 432,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                                "line": 432,
                                                                "char": 48
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 432,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 432,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 433,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 435,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "byteString",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "alphabet",
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 435,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "cast",
                                                    "left": "int",
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "idx",
                                                        "file": "\/app\/phalcon\/Security\/Random.zep",
                                                        "line": 435,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                                    "line": 435,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                                "line": 435,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Security\/Random.zep",
                                            "line": 435,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security\/Random.zep",
                                    "line": 436,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 438,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "byteString",
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 438,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Security\/Random.zep",
                            "line": 439,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a random string based on the number ($base) of characters\n     * ($alphabet).\n     *\n     * If $n is not specified, 16 is assumed. It may be larger in future.\n     *\n     * @throws Exception If secure random number generator is not available or unexpected partial read\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security\/Random.zep",
                                "line": 419,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security\/Random.zep",
                        "line": 419,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security\/Random.zep",
                    "line": 418,
                    "last-line": 440,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Security\/Random.zep",
            "line": 85,
            "char": 5
        },
        "file": "\/app\/phalcon\/Security\/Random.zep",
        "line": 85,
        "char": 5
    }
]