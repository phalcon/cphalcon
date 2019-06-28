[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Crypt.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Crypt.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\CryptInterface",
                "file": "\/app\/phalcon\/Crypt.zep",
                "line": 13,
                "char": 27
            }
        ],
        "file": "\/app\/phalcon\/Crypt.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Crypt\\Exception",
                "file": "\/app\/phalcon\/Crypt.zep",
                "line": 14,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Crypt.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Crypt\\Mismatch",
                "file": "\/app\/phalcon\/Crypt.zep",
                "line": 15,
                "char": 27
            }
        ],
        "file": "\/app\/phalcon\/Crypt.zep",
        "line": 34,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Provides encryption capabilities to Phalcon applications.\n *\n * ```php\n * use Phalcon\\Crypt;\n *\n * $crypt = new Crypt();\n *\n * $crypt->setCipher('aes-256-ctr');\n *\n * $key  = \"T4\\xb1\\x8d\\xa9\\x98\\x05\\\\\\x8c\\xbe\\x1d\\x07&[\\x99\\x18\\xa4~Lc1\\xbeW\\xb3\";\n * $text = \"The message to be encrypted\";\n *\n * $encrypted = $crypt->encrypt($text, $key);\n *\n * echo $crypt->decrypt($encrypted, $key);\n * ```\n *",
        "file": "\/app\/phalcon\/Crypt.zep",
        "line": 35,
        "char": 5
    },
    {
        "type": "class",
        "name": "Crypt",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "CryptInterface",
                "file": "\/app\/phalcon\/Crypt.zep",
                "line": 36,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "authTag",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 48,
                            "char": 29
                        }
                    ],
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 51,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "authData",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 52,
                        "char": 27
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 52,
                            "char": 33
                        }
                    ],
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 55,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "authTagLength",
                    "default": {
                        "type": "int",
                        "value": "16",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 56,
                        "char": 34
                    },
                    "docblock": "**\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 56,
                            "char": 40
                        }
                    ],
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 59,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "key",
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 64,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "padding",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 65,
                        "char": 26
                    },
                    "docblock": "**\n     * @var int\n     *",
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 69,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "cipher",
                    "default": {
                        "type": "string",
                        "value": "aes-256-cfb",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 70,
                        "char": 35
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 75,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "availableCiphers",
                    "docblock": "**\n     * Available cipher methods.\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 81,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "ivLength",
                    "default": {
                        "type": "int",
                        "value": "16",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 82,
                        "char": 28
                    },
                    "docblock": "**\n     * The cipher iv length.\n     * @var int\n     *",
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 87,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "hashAlgo",
                    "default": {
                        "type": "string",
                        "value": "sha256",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 88,
                        "char": 32
                    },
                    "docblock": "**\n     * The name of hashing algorithm.\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 94,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "useSigning",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 95,
                        "char": 32
                    },
                    "docblock": "**\n     * Whether calculating message digest enabled or not.\n     *\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 99,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__construct",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cipher",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "aes-256-cfb",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 100,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 100,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "useSigning",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 100,
                                "char": 86
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 100,
                            "char": 86
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 102,
                                    "char": 14
                                },
                                "name": "initializeAvailableCiphers",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 102,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 104,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 104,
                                    "char": 14
                                },
                                "name": "setCipher",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cipher",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 104,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 104,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 104,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 105,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 105,
                                    "char": 14
                                },
                                "name": "useSigning",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "useSigning",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 105,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 105,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 105,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 106,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Crypt constructor.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 101,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 100,
                    "last-line": 117,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "decrypt",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 118,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 118,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 118,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "authData",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 120,
                                    "char": 21
                                },
                                {
                                    "variable": "authTag",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 120,
                                    "char": 30
                                },
                                {
                                    "variable": "decryptKey",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 120,
                                    "char": 42
                                },
                                {
                                    "variable": "ivLength",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 120,
                                    "char": 52
                                },
                                {
                                    "variable": "cipher",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 120,
                                    "char": 60
                                },
                                {
                                    "variable": "mode",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 120,
                                    "char": 66
                                },
                                {
                                    "variable": "blockSize",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 120,
                                    "char": 77
                                },
                                {
                                    "variable": "decrypted",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 121,
                                    "char": 22
                                },
                                {
                                    "variable": "ciphertext",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 121,
                                    "char": 34
                                },
                                {
                                    "variable": "hashAlgo",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 121,
                                    "char": 44
                                },
                                {
                                    "variable": "hashLength",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 121,
                                    "char": 56
                                },
                                {
                                    "variable": "iv",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 121,
                                    "char": 60
                                },
                                {
                                    "variable": "hash",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 121,
                                    "char": 66
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 123,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "key",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 123,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 123,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 123,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "decryptKey",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 124,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 124,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 124,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 124,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 125,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "decryptKey",
                                            "expr": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 126,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 126,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 127,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 129,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "decryptKey",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 129,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 129,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 129,
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
                                                    "value": "Decryption key cannot be empty",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 130,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 130,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 130,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 131,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 133,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cipher",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 133,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "cipher",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 133,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 133,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 133,
                                    "char": 36
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mode",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtolower",
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
                                                                "value": "cipher",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 134,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 134,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "sub",
                                                                "left": {
                                                                    "type": "fcall",
                                                                    "name": "strrpos",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "cipher",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 134,
                                                                                "char": 64
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 134,
                                                                            "char": 64
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "-",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 134,
                                                                                "char": 67
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 134,
                                                                            "char": 67
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 134,
                                                                    "char": 69
                                                                },
                                                                "right": {
                                                                    "type": "fcall",
                                                                    "name": "strlen",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "cipher",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 134,
                                                                                "char": 84
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 134,
                                                                            "char": 84
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 134,
                                                                    "char": 85
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 134,
                                                                "char": 85
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 134,
                                                            "char": 85
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 134,
                                                    "char": 86
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 134,
                                                "char": 86
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 134,
                                        "char": 87
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 134,
                                    "char": 87
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "authData",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 135,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "authData",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 135,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 135,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 135,
                                    "char": 38
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "authTag",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 136,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "authTag",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 136,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 136,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 136,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 138,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 138,
                                    "char": 14
                                },
                                "name": "assertCipherIsAvailable",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cipher",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 138,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 138,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 138,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 140,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ivLength",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 140,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "ivLength",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 140,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 140,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 140,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 142,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "greater",
                                    "left": {
                                        "type": "variable",
                                        "value": "ivLength",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 142,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 142,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 142,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 142,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "blockSize",
                                            "expr": {
                                                "type": "variable",
                                                "value": "ivLength",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 143,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 143,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 144,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "blockSize",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 145,
                                                    "char": 34
                                                },
                                                "name": "getIvLength",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "str_ireplace",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "string",
                                                                            "value": "-",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 145,
                                                                            "char": 62
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "mode",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 145,
                                                                            "char": 68
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 145,
                                                                        "char": 68
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 145,
                                                                    "char": 68
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 145,
                                                                        "char": 70
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 145,
                                                                    "char": 70
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "cipher",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 145,
                                                                        "char": 78
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 145,
                                                                    "char": 78
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 145,
                                                            "char": 79
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 145,
                                                        "char": 79
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 145,
                                                "char": 80
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 145,
                                            "char": 80
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 146,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 148,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "iv",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "mb_substr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 148,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 148,
                                                "char": 32
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 148,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 148,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ivLength",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 148,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 148,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "8bit",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 148,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 148,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 148,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 148,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 150,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 150,
                                    "char": 17
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "useSigning",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 150,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 150,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "hashAlgo",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 151,
                                                    "char": 35
                                                },
                                                "name": "getHashAlgo",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 151,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 151,
                                            "char": 49
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "hashLength",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "strlen",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "hash",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "hashAlgo",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 152,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 152,
                                                                    "char": 50
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 152,
                                                                        "char": 52
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 152,
                                                                    "char": 52
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "bool",
                                                                        "value": "true",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 152,
                                                                        "char": 58
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 152,
                                                                    "char": 58
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 152,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 152,
                                                        "char": 59
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 152,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 152,
                                            "char": 60
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "hash",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "mb_substr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "text",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 153,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 153,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "ivLength",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 153,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 153,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "hashLength",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 153,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 153,
                                                        "char": 66
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "8bit",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 153,
                                                            "char": 72
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 153,
                                                        "char": 72
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 153,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 153,
                                            "char": 73
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "ciphertext",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "mb_substr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "text",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 154,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 154,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "add",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "ivLength",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 154,
                                                                "char": 55
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "hashLength",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 154,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 154,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 154,
                                                        "char": 67
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "null",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 154,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 154,
                                                        "char": 73
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "8bit",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 154,
                                                            "char": 79
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 154,
                                                        "char": 79
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 154,
                                                "char": 80
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 154,
                                            "char": 80
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 156,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "or",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "-gcm",
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 156,
                                                        "char": 24
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mode",
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 156,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 156,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "-ccm",
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 156,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mode",
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 156,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 156,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 156,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 156,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 156,
                                                        "char": 64
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "authData",
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 156,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 156,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 156,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 156,
                                            "char": 74
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 156,
                                        "char": 74
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "decrypted",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "openssl_decrypt",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "ciphertext",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 158,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 158,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "cipher",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 159,
                                                                    "char": 27
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 159,
                                                                "char": 27
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "decryptKey",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 160,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 160,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "constant",
                                                                    "value": "OPENSSL_RAW_DATA",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 161,
                                                                    "char": 37
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 161,
                                                                "char": 37
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "iv",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 162,
                                                                    "char": 23
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 162,
                                                                "char": 23
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "authTag",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 163,
                                                                    "char": 28
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 163,
                                                                "char": 28
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "authData",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 165,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 165,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 165,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 165,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 166,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "decrypted",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "openssl_decrypt",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "ciphertext",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 168,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 168,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "cipher",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 169,
                                                                    "char": 27
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 169,
                                                                "char": 27
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "decryptKey",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 170,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 170,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "constant",
                                                                    "value": "OPENSSL_RAW_DATA",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 171,
                                                                    "char": 37
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 171,
                                                                "char": 37
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "iv",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 173,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 173,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 173,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 173,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 174,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 176,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "or",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "mode",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 176,
                                                "char": 22
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "-cbc",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 176,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 176,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "mode",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 176,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "-ecb",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 176,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 176,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 176,
                                        "char": 45
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "decrypted",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 177,
                                                            "char": 38
                                                        },
                                                        "name": "cryptUnpadText",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "decrypted",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 177,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 177,
                                                                "char": 63
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "mode",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 177,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 177,
                                                                "char": 69
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "blockSize",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 177,
                                                                    "char": 80
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 177,
                                                                "char": 80
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 177,
                                                                        "char": 87
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "padding",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 177,
                                                                        "char": 95
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 177,
                                                                    "char": 95
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 177,
                                                                "char": 95
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 177,
                                                        "char": 96
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 177,
                                                    "char": 96
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 178,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 183,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "fcall",
                                                "name": "hash_hmac",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "hashAlgo",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 183,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 183,
                                                        "char": 43
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "decrypted",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 183,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 183,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "decryptKey",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 183,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 183,
                                                        "char": 66
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 183,
                                                            "char": 72
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 183,
                                                        "char": 72
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 183,
                                                "char": 76
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "hash",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 183,
                                                "char": 83
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 183,
                                            "char": 83
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 183,
                                        "char": 83
                                    },
                                    "statements": [
                                        {
                                            "type": "throw",
                                            "expr": {
                                                "type": "new",
                                                "class": "Mismatch",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "Hash does not match.",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 184,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 184,
                                                        "char": 56
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 184,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 185,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 187,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "decrypted",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 187,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 188,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 190,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ciphertext",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "mb_substr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 190,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 190,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ivLength",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 190,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 190,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 190,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 190,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "8bit",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 190,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 190,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 190,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 190,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 192,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "or",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "string",
                                                "value": "-gcm",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 192,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "mode",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 192,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 192,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "identical",
                                            "left": {
                                                "type": "string",
                                                "value": "-ccm",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 192,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "mode",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 192,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 192,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 192,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 192,
                                    "char": 46
                                },
                                "right": {
                                    "type": "not",
                                    "left": {
                                        "type": "empty",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 192,
                                                "char": 60
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "authData",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 192,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 192,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 192,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 192,
                                    "char": 70
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 192,
                                "char": 70
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "decrypted",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "openssl_decrypt",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "ciphertext",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 194,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 194,
                                                        "char": 27
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "cipher",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 195,
                                                            "char": 23
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 195,
                                                        "char": 23
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "decryptKey",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 196,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 196,
                                                        "char": 27
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "constant",
                                                            "value": "OPENSSL_RAW_DATA",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 197,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 197,
                                                        "char": 33
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "iv",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 198,
                                                            "char": 19
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 198,
                                                        "char": 19
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "authTag",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 199,
                                                            "char": 24
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 199,
                                                        "char": 24
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "authData",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 201,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 201,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 201,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 201,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 202,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "decrypted",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "openssl_decrypt",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "ciphertext",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 204,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 204,
                                                        "char": 27
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "cipher",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 205,
                                                            "char": 23
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 205,
                                                        "char": 23
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "decryptKey",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 206,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 206,
                                                        "char": 27
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "constant",
                                                            "value": "OPENSSL_RAW_DATA",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 207,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 207,
                                                        "char": 33
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "iv",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 209,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 209,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 209,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 209,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 210,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 212,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "mode",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 212,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "-cbc",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 212,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 212,
                                    "char": 26
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "mode",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 212,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "-ecb",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 212,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 212,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 212,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "decrypted",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 213,
                                                    "char": 34
                                                },
                                                "name": "cryptUnpadText",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "decrypted",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 214,
                                                            "char": 26
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 214,
                                                        "char": 26
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "mode",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 215,
                                                            "char": 21
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 215,
                                                        "char": 21
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "blockSize",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 216,
                                                            "char": 26
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 216,
                                                        "char": 26
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 217,
                                                                "char": 22
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "padding",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 218,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 218,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 218,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 218,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 218,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 219,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 221,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "decrypted",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 221,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 222,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Decrypts an encrypted text.\n     *\n     * ```php\n     * $encrypted = $crypt->decrypt(\n     *     $encrypted,\n     *     \"T4\\xb1\\x8d\\xa9\\x98\\x05\\\\\\x8c\\xbe\\x1d\\x07&[\\x99\\x18\\xa4~Lc1\\xbeW\\xb3\"\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 119,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 119,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 118,
                    "last-line": 228,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "decryptBase64",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 229,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 229,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 229,
                            "char": 59
                        },
                        {
                            "type": "parameter",
                            "name": "safe",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 1,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 229,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 229,
                            "char": 79
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "safe",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 231,
                                "char": 17
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "text",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "strtr",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "text",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 232,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 232,
                                                            "char": 34
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "-_",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 232,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 232,
                                                            "char": 38
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "+\/",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 232,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 232,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 232,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "substr",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "===",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 232,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 232,
                                                            "char": 56
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "mod",
                                                                "left": {
                                                                    "type": "list",
                                                                    "left": {
                                                                        "type": "add",
                                                                        "left": {
                                                                            "type": "fcall",
                                                                            "name": "strlen",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "text",
                                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                                        "line": 232,
                                                                                        "char": 70
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 232,
                                                                                    "char": 70
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 232,
                                                                            "char": 72
                                                                        },
                                                                        "right": {
                                                                            "type": "int",
                                                                            "value": "3",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 232,
                                                                            "char": 75
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 232,
                                                                        "char": 75
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 232,
                                                                    "char": 77
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "4",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 232,
                                                                    "char": 80
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 232,
                                                                "char": 80
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 232,
                                                            "char": 80
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 232,
                                                    "char": 81
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 232,
                                                "char": 81
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 232,
                                            "char": 81
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 233,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 235,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 235,
                                    "char": 21
                                },
                                "name": "decrypt",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "base64_decode",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "text",
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 236,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 236,
                                                    "char": 31
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 236,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 236,
                                        "char": 32
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 238,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 238,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 238,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 239,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Decrypt a text that is coded as a base64 string.\n     *\n     * @throws \\Phalcon\\Crypt\\Mismatch\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 230,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 230,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 229,
                    "last-line": 250,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "encrypt",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 251,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 251,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 251,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "authData",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 253,
                                    "char": 21
                                },
                                {
                                    "variable": "authTag",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 253,
                                    "char": 30
                                },
                                {
                                    "variable": "authTagLength",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 253,
                                    "char": 45
                                },
                                {
                                    "variable": "encryptKey",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 253,
                                    "char": 57
                                },
                                {
                                    "variable": "ivLength",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 253,
                                    "char": 67
                                },
                                {
                                    "variable": "iv",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 253,
                                    "char": 71
                                },
                                {
                                    "variable": "cipher",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 254,
                                    "char": 19
                                },
                                {
                                    "variable": "mode",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 254,
                                    "char": 25
                                },
                                {
                                    "variable": "blockSize",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 254,
                                    "char": 36
                                },
                                {
                                    "variable": "paddingType",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 254,
                                    "char": 49
                                },
                                {
                                    "variable": "padded",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 254,
                                    "char": 57
                                },
                                {
                                    "variable": "encrypted",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 254,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 256,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "key",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 256,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 256,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 256,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "encryptKey",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 257,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 257,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 257,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 257,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 258,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "encryptKey",
                                            "expr": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 259,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 259,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 260,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 262,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "encryptKey",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 262,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 262,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 262,
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
                                                    "value": "Encryption key cannot be empty",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 263,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 263,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 263,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 264,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 266,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cipher",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 266,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "cipher",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 266,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 266,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 266,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 268,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mode",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtolower",
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
                                                                "value": "cipher",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 270,
                                                                "char": 23
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 270,
                                                            "char": 23
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "sub",
                                                                "left": {
                                                                    "type": "fcall",
                                                                    "name": "strrpos",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "cipher",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 271,
                                                                                "char": 31
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 271,
                                                                            "char": 31
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "-",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 271,
                                                                                "char": 34
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 271,
                                                                            "char": 34
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 271,
                                                                    "char": 36
                                                                },
                                                                "right": {
                                                                    "type": "fcall",
                                                                    "name": "strlen",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "cipher",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 271,
                                                                                "char": 51
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 271,
                                                                            "char": 51
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 272,
                                                                    "char": 13
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 272,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 272,
                                                            "char": 13
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 273,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 273,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 273,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 273,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 275,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 275,
                                    "char": 14
                                },
                                "name": "assertCipherIsAvailable",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cipher",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 275,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 275,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 275,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 277,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ivLength",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 277,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "ivLength",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 277,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 277,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 277,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 279,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "greater",
                                    "left": {
                                        "type": "variable",
                                        "value": "ivLength",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 279,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 279,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 279,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 279,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "blockSize",
                                            "expr": {
                                                "type": "variable",
                                                "value": "ivLength",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 280,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 280,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 281,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "blockSize",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 282,
                                                    "char": 34
                                                },
                                                "name": "getIvLength",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "str_ireplace",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "string",
                                                                            "value": "-",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 284,
                                                                            "char": 23
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "mode",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 284,
                                                                            "char": 29
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 284,
                                                                        "char": 29
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 284,
                                                                    "char": 29
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 285,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 285,
                                                                    "char": 21
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "cipher",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 287,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 287,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 288,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 288,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 288,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 288,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 289,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 291,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "iv",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "openssl_random_pseudo_bytes",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ivLength",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 291,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 291,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 291,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 291,
                                    "char": 64
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "paddingType",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 292,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "padding",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 292,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 292,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 292,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 294,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "paddingType",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 294,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 294,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 294,
                                    "char": 30
                                },
                                "right": {
                                    "type": "list",
                                    "left": {
                                        "type": "or",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "mode",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 294,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "-cbc",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 294,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 294,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "mode",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 294,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "-ecb",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 294,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 294,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 294,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 294,
                                    "char": 63
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 294,
                                "char": 63
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "padded",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 295,
                                                    "char": 31
                                                },
                                                "name": "cryptPadText",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "text",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 295,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 295,
                                                        "char": 49
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "mode",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 295,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 295,
                                                        "char": 55
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "blockSize",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 295,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 295,
                                                        "char": 66
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "paddingType",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 295,
                                                            "char": 79
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 295,
                                                        "char": 79
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 295,
                                                "char": 80
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 295,
                                            "char": 80
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 296,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "padded",
                                            "expr": {
                                                "type": "variable",
                                                "value": "text",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 297,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 297,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 298,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 304,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "or",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "string",
                                                "value": "-gcm",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 304,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "mode",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 304,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 304,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "identical",
                                            "left": {
                                                "type": "string",
                                                "value": "-ccm",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 304,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "mode",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 304,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 304,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 304,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 304,
                                    "char": 46
                                },
                                "right": {
                                    "type": "not",
                                    "left": {
                                        "type": "empty",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 304,
                                                "char": 60
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "authData",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 304,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 304,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 304,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 304,
                                    "char": 70
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 304,
                                "char": 70
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "authData",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 305,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "authData",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 305,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 305,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 305,
                                            "char": 47
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "authTag",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 306,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "authTag",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 306,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 306,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 306,
                                            "char": 46
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "authTagLength",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 307,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "authTagLength",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 307,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 307,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 307,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 309,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "encrypted",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "openssl_encrypt",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "padded",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 310,
                                                            "char": 23
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 310,
                                                        "char": 23
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "cipher",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 311,
                                                            "char": 23
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 311,
                                                        "char": 23
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "encryptKey",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 312,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 312,
                                                        "char": 27
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "constant",
                                                            "value": "OPENSSL_RAW_DATA",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 313,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 313,
                                                        "char": 33
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "iv",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 314,
                                                            "char": 19
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 314,
                                                        "char": 19
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "authTag",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 315,
                                                            "char": 24
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 315,
                                                        "char": 24
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "authData",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 316,
                                                            "char": 25
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 316,
                                                        "char": 25
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "authTagLength",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 318,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 318,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 318,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 318,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 320,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "authTag",
                                            "expr": {
                                                "type": "variable",
                                                "value": "authTag",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 320,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 320,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 321,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "encrypted",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "openssl_encrypt",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "padded",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 323,
                                                            "char": 23
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 323,
                                                        "char": 23
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "cipher",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 324,
                                                            "char": 23
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 324,
                                                        "char": 23
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "encryptKey",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 325,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 325,
                                                        "char": 27
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "constant",
                                                            "value": "OPENSSL_RAW_DATA",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 326,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 326,
                                                        "char": 33
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "iv",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 328,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 328,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 328,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 328,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 329,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 331,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 331,
                                    "char": 17
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "useSigning",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 331,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 331,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "declare",
                                    "data-type": "variable",
                                    "variables": [
                                        {
                                            "variable": "digest",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 332,
                                            "char": 23
                                        },
                                        {
                                            "variable": "hashAlgo",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 332,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 334,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "hashAlgo",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 334,
                                                    "char": 33
                                                },
                                                "name": "getHashAlgo",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 334,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 334,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 335,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "digest",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "hash_hmac",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "hashAlgo",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 335,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 335,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "padded",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 335,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 335,
                                                        "char": 52
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "encryptKey",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 335,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 335,
                                                        "char": 64
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 335,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 335,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 335,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 335,
                                            "char": 71
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 337,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "variable",
                                                "value": "iv",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 337,
                                                "char": 23
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "digest",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 337,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 337,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "encrypted",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 337,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 337,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 338,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 340,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "variable",
                                    "value": "iv",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 340,
                                    "char": 19
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "encrypted",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 340,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 340,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 341,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Encrypts a text.\n     *\n     * ```php\n     * $encrypted = $crypt->encrypt(\n     *     \"Top secret\",\n     *     \"T4\\xb1\\x8d\\xa9\\x98\\x05\\\\\\x8c\\xbe\\x1d\\x07&[\\x99\\x18\\xa4~Lc1\\xbeW\\xb3\"\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 252,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 252,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 251,
                    "last-line": 345,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "encryptBase64",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 346,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 346,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 346,
                            "char": 59
                        },
                        {
                            "type": "parameter",
                            "name": "safe",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 1,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 346,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 346,
                            "char": 79
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "safe",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 348,
                                    "char": 18
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 348,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 348,
                                "char": 25
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
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 352,
                                                                                "char": 30
                                                                            },
                                                                            "name": "encrypt",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "text",
                                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                                        "line": 352,
                                                                                        "char": 43
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 352,
                                                                                    "char": 43
                                                                                },
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "key",
                                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                                        "line": 352,
                                                                                        "char": 48
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 352,
                                                                                    "char": 48
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 353,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 353,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 353,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 353,
                                                            "char": 22
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "+\/",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 354,
                                                                "char": 23
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 354,
                                                            "char": 23
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "-_",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 356,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 356,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 356,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 356,
                                                "char": 18
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "=",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 358,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 358,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 358,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 359,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 361,
                            "char": 14
                        },
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
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 362,
                                                "char": 18
                                            },
                                            "name": "encrypt",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "text",
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 362,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 362,
                                                    "char": 31
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 362,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 362,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 363,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 363,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 363,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 364,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Encrypts a text returning the result as a base64 string.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 347,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 347,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 346,
                    "last-line": 368,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAvailableCiphers",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "availableCiphers",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 371,
                                    "char": 29
                                },
                                {
                                    "variable": "cipher",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 371,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 372,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "allowedCiphers",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 372,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 374,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "availableCiphers",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 374,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "availableCiphers",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 374,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 374,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 374,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 376,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "availableCiphers",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 376,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 376,
                                        "char": 47
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 376,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 376,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 376,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 377,
                                            "char": 18
                                        },
                                        "name": "initializeAvailableCiphers",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 377,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 379,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "availableCiphers",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 379,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "availableCiphers",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 379,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 379,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 379,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 380,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 382,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "allowedCiphers",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 382,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 382,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 383,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "availableCiphers",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 383,
                                "char": 40
                            },
                            "value": "cipher",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "or",
                                                "left": {
                                                    "type": "or",
                                                    "left": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "or",
                                                            "left": {
                                                                "type": "fcall",
                                                                "name": "starts_with",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "fcall",
                                                                            "name": "strtolower",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "cipher",
                                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                                        "line": 384,
                                                                                        "char": 47
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 384,
                                                                                    "char": 47
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 384,
                                                                            "char": 48
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 384,
                                                                        "char": 48
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "des",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 384,
                                                                            "char": 53
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 384,
                                                                        "char": 53
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 384,
                                                                "char": 56
                                                            },
                                                            "right": {
                                                                "type": "fcall",
                                                                "name": "starts_with",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "fcall",
                                                                            "name": "strtolower",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "cipher",
                                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                                        "line": 385,
                                                                                        "char": 47
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 385,
                                                                                    "char": 47
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 385,
                                                                            "char": 48
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 385,
                                                                        "char": 48
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "rc2",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 385,
                                                                            "char": 53
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 385,
                                                                        "char": 53
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 385,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 385,
                                                            "char": 56
                                                        },
                                                        "right": {
                                                            "type": "fcall",
                                                            "name": "starts_with",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "fcall",
                                                                        "name": "strtolower",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "cipher",
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 386,
                                                                                    "char": 47
                                                                                },
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 386,
                                                                                "char": 47
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 386,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 386,
                                                                    "char": 48
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "rc4",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 386,
                                                                        "char": 53
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 386,
                                                                    "char": 53
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 386,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 386,
                                                        "char": 56
                                                    },
                                                    "right": {
                                                        "type": "fcall",
                                                        "name": "starts_with",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "fcall",
                                                                    "name": "strtolower",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "cipher",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 387,
                                                                                "char": 47
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 387,
                                                                            "char": 47
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 387,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 387,
                                                                "char": 48
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "des",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 387,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 387,
                                                                "char": 53
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 387,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 387,
                                                    "char": 56
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "ends_with",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "fcall",
                                                                "name": "strtolower",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "cipher",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 388,
                                                                            "char": 45
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 388,
                                                                        "char": 45
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 388,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 388,
                                                            "char": 46
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "ecb",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 388,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 388,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 388,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 388,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 388,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 388,
                                        "char": 54
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "allowedCiphers",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "cipher",
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 389,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 389,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 390,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 391,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 393,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "allowedCiphers",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 393,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 394,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a list of available ciphers.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 370,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 370,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 369,
                    "last-line": 398,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAvailableHashAlgos",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "algos",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 401,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 403,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "fcall",
                                    "name": "function_exists",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "hash_hmac_algos",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 403,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 403,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 403,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 403,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "algos",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "hash_hmac_algos",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 404,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 404,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 405,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "algos",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "hash_algos",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 406,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 406,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 407,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 409,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "algos",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 409,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 410,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return a list of registered hashing algorithms suitable for hash_hmac.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 400,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 400,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 399,
                    "last-line": 414,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCipher",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 417,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "cipher",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 417,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 417,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 418,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current cipher\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 416,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 416,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 415,
                    "last-line": 422,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHashAlgo",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 425,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "hashAlgo",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 425,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 425,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 426,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get the name of hashing algorithm.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 424,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 424,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 423,
                    "last-line": 430,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getKey",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 433,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "key",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 433,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 433,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 434,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the encryption key\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 432,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 432,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 431,
                    "last-line": 436,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAuthTag",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tag",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 436,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "authTag",
                                    "expr": {
                                        "type": "variable",
                                        "value": "tag",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 438,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 438,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 440,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 440,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 441,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 437,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 437,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 437,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 436,
                    "last-line": 443,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAuthData",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 443,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "authData",
                                    "expr": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 445,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 445,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 447,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 447,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 448,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 444,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 444,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 444,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 443,
                    "last-line": 450,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAuthTagLength",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "length",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 450,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "authTagLength",
                                    "expr": {
                                        "type": "variable",
                                        "value": "length",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 452,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 452,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 454,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 454,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 455,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 451,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 451,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 451,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 450,
                    "last-line": 465,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setCipher",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cipher",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 466,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 468,
                                    "char": 14
                                },
                                "name": "assertCipherIsAvailable",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cipher",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 468,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 468,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 468,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 470,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "ivLength",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 470,
                                            "char": 35
                                        },
                                        "name": "getIvLength",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cipher",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 470,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 470,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 470,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 470,
                                    "char": 55
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "cipher",
                                    "expr": {
                                        "type": "variable",
                                        "value": "cipher",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 471,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 471,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 473,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 473,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 474,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the cipher algorithm for data encryption and decryption.\n     *\n     * The `aes-256-gcm' is the preferable cipher, but it is not usable\n     * until the openssl library is upgraded, which is available in PHP 7.1.\n     *\n     * The `aes-256-ctr' is arguably the best choice for cipher\n     * algorithm for current openssl library version.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 467,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 467,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 467,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 466,
                    "last-line": 480,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHashAlgo",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "hashAlgo",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 481,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 483,
                                    "char": 14
                                },
                                "name": "assertHashAlgorithmAvailable",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "hashAlgo",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 483,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 483,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 483,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 485,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "hashAlgo",
                                    "expr": {
                                        "type": "variable",
                                        "value": "hashAlgo",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 485,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 485,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 487,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 487,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 488,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the name of hashing algorithm.\n     *\n     * @throws \\Phalcon\\Crypt\\Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 482,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 482,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 482,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 481,
                    "last-line": 504,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setKey",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 505,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "key",
                                    "expr": {
                                        "type": "variable",
                                        "value": "key",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 507,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 507,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 509,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 509,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 510,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the encryption key.\n     *\n     * The `$key' should have been previously generated in a cryptographically\n     * safe way.\n     *\n     * Bad key:\n     * \"le password\"\n     *\n     * Better (but still unsafe):\n     * \"#1dj8$=dp?.ak\/\/j1V$~%*0X\"\n     *\n     * Good key:\n     * \"T4\\xb1\\x8d\\xa9\\x98\\x05\\\\\\x8c\\xbe\\x1d\\x07&[\\x99\\x18\\xa4~Lc1\\xbeW\\xb3\"\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 506,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 506,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 506,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 505,
                    "last-line": 514,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setPadding",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "scheme",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 515,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "padding",
                                    "expr": {
                                        "type": "variable",
                                        "value": "scheme",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 517,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 517,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 519,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 519,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 520,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Changes the padding scheme used.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 516,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 516,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 516,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 515,
                    "last-line": 524,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "useSigning",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "useSigning",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 525,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "useSigning",
                                    "expr": {
                                        "type": "variable",
                                        "value": "useSigning",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 527,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 527,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 529,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 529,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 530,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if the calculating message digest must used.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 526,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 526,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 526,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 525,
                    "last-line": 534,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "assertCipherIsAvailable",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cipher",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 535,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "availableCiphers",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 537,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 539,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "availableCiphers",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 539,
                                            "char": 37
                                        },
                                        "name": "getAvailableCiphers",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 539,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 539,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 541,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "in_array",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cipher",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 541,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 541,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "availableCiphers",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 541,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 541,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 541,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 541,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 541,
                                "char": 57
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
                                                    "type": "fcall",
                                                    "name": "sprintf",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "The cipher algorithm \\\"%s\\\" is not supported on this system.",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 544,
                                                                "char": 81
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 544,
                                                            "char": 81
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "cipher",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 546,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 546,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 547,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 547,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 547,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 548,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 549,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Assert the cipher is available.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 536,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 535,
                    "last-line": 553,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "assertHashAlgorithmAvailable",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "hashAlgo",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 554,
                            "char": 69
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "availableAlgorithms",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 556,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 558,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "availableAlgorithms",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 558,
                                            "char": 40
                                        },
                                        "name": "getAvailableHashAlgos",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 558,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 558,
                                    "char": 64
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 560,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "in_array",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "hashAlgo",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 560,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 560,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "availableAlgorithms",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 560,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 560,
                                                "char": 60
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 560,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 560,
                                    "char": 62
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 560,
                                "char": 62
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
                                                    "type": "fcall",
                                                    "name": "sprintf",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "The hash algorithm \\\"%s\\\" is not supported on this system.",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 563,
                                                                "char": 79
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 563,
                                                            "char": 79
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "hashAlgo",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 565,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 565,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 566,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 566,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 566,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 567,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 568,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Assert the hash algorithm is available.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 555,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 554,
                    "last-line": 572,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getIvLength",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cipher",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 573,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "function_exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "openssl_cipher_iv_length",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 575,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 575,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 575,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 575,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 575,
                                "char": 64
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
                                                    "value": "openssl extension is required",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 576,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 576,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 576,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 577,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 579,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "openssl_cipher_iv_length",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cipher",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 579,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 579,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 579,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 580,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Initialize available cipher algorithms.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 574,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 574,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 573,
                    "last-line": 584,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "initializeAvailableCiphers",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "function_exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "openssl_get_cipher_methods",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 587,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 587,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 587,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 587,
                                    "char": 66
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 587,
                                "char": 66
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
                                                    "value": "openssl extension is required",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 588,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 588,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 588,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 589,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 591,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "availableCiphers",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "openssl_get_cipher_methods",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 591,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 591,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 591,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 591,
                                    "char": 70
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 592,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Initialize available cipher algorithms.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 586,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 585,
                    "last-line": 596,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "cryptPadText",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 597,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "mode",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 597,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "blockSize",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 597,
                            "char": 78
                        },
                        {
                            "type": "parameter",
                            "name": "paddingType",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 597,
                            "char": 96
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "i",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 599,
                                    "char": 14
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 600,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "paddingSize",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 600,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 600,
                                    "char": 28
                                },
                                {
                                    "variable": "padding",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 600,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 600,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 602,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "mode",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 602,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "cbc",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 602,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 602,
                                    "char": 25
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "mode",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 602,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "ecb",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 602,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 602,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 602,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "paddingSize",
                                            "expr": {
                                                "type": "sub",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "blockSize",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 603,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "mod",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "strlen",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "text",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 603,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 603,
                                                                    "char": 55
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 603,
                                                            "char": 57
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "blockSize",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 603,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 603,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 603,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 603,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 603,
                                            "char": 69
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 605,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "greater-equal",
                                            "left": {
                                                "type": "variable",
                                                "value": "paddingSize",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 605,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "256",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 605,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 605,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 605,
                                        "char": 43
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
                                                            "value": "Block size is bigger than 256",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 606,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 606,
                                                        "char": 66
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 606,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 607,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 609,
                                    "char": 18
                                },
                                {
                                    "type": "switch",
                                    "expr": {
                                        "type": "variable",
                                        "value": "paddingType",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 609,
                                        "char": 32
                                    },
                                    "clauses": [
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 611,
                                                    "char": 46
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PADDING_ANSI_X_923",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 611,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 611,
                                                "char": 46
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "padding",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "fcall",
                                                                    "name": "str_repeat",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "fcall",
                                                                                "name": "chr",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "int",
                                                                                            "value": "0",
                                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                                            "line": 612,
                                                                                            "char": 51
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                                        "line": 612,
                                                                                        "char": 51
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 612,
                                                                                "char": 52
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 612,
                                                                            "char": 52
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "sub",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "paddingSize",
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 612,
                                                                                    "char": 66
                                                                                },
                                                                                "right": {
                                                                                    "type": "int",
                                                                                    "value": "1",
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 612,
                                                                                    "char": 69
                                                                                },
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 612,
                                                                                "char": 69
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 612,
                                                                            "char": 69
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 612,
                                                                    "char": 71
                                                                },
                                                                "right": {
                                                                    "type": "fcall",
                                                                    "name": "chr",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "paddingSize",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 612,
                                                                                "char": 88
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 612,
                                                                            "char": 88
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 612,
                                                                    "char": 89
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 612,
                                                                "char": 89
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 612,
                                                            "char": 89
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 613,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 615,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 615,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 615,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PADDING_PKCS7",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 615,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 615,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "padding",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "str_repeat",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "fcall",
                                                                            "name": "chr",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "paddingSize",
                                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                                        "line": 616,
                                                                                        "char": 61
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 616,
                                                                                    "char": 61
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 616,
                                                                            "char": 62
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 616,
                                                                        "char": 62
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "paddingSize",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 616,
                                                                            "char": 75
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 616,
                                                                        "char": 75
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 616,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 616,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 617,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 619,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 619,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 619,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PADDING_ISO_10126",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 619,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 619,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "padding",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 620,
                                                                "char": 35
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 620,
                                                            "char": 35
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 622,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "range",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 622,
                                                                    "char": 37
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 622,
                                                                "char": 37
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "sub",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "paddingSize",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 622,
                                                                        "char": 51
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "2",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 622,
                                                                        "char": 54
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 622,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 622,
                                                                "char": 54
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 622,
                                                        "char": 56
                                                    },
                                                    "value": "i",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "padding",
                                                                    "expr": {
                                                                        "type": "fcall",
                                                                        "name": "chr",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "fcall",
                                                                                    "name": "rand",
                                                                                    "call-type": 1,
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 623,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 623,
                                                                                "char": 49
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 623,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 623,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 624,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 626,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "padding",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "chr",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "paddingSize",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 626,
                                                                            "char": 50
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 626,
                                                                        "char": 50
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 626,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 626,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 628,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 630,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 630,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 630,
                                                    "char": 50
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PADDING_ISO_IEC_7816_4",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 630,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 630,
                                                "char": 50
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "padding",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "fcall",
                                                                    "name": "chr",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "int",
                                                                                "value": "0x80",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 631,
                                                                                "char": 43
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 631,
                                                                            "char": 43
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 631,
                                                                    "char": 45
                                                                },
                                                                "right": {
                                                                    "type": "fcall",
                                                                    "name": "str_repeat",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "fcall",
                                                                                "name": "chr",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "int",
                                                                                            "value": "0",
                                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                                            "line": 631,
                                                                                            "char": 63
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                                        "line": 631,
                                                                                        "char": 63
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 631,
                                                                                "char": 64
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 631,
                                                                            "char": 64
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "sub",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "paddingSize",
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 631,
                                                                                    "char": 78
                                                                                },
                                                                                "right": {
                                                                                    "type": "int",
                                                                                    "value": "1",
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 631,
                                                                                    "char": 81
                                                                                },
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 631,
                                                                                "char": 81
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 631,
                                                                            "char": 81
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 631,
                                                                    "char": 82
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 631,
                                                                "char": 82
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 631,
                                                            "char": 82
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 632,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 634,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 634,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 634,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PADDING_ZERO",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 634,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 634,
                                                "char": 40
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "padding",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "str_repeat",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "fcall",
                                                                            "name": "chr",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "int",
                                                                                        "value": "0",
                                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                                        "line": 635,
                                                                                        "char": 51
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 635,
                                                                                    "char": 51
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 635,
                                                                            "char": 52
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 635,
                                                                        "char": 52
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "paddingSize",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 635,
                                                                            "char": 65
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 635,
                                                                        "char": 65
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 635,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 635,
                                                            "char": 66
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 636,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 638,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 638,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 638,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PADDING_SPACE",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 638,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 638,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "padding",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "str_repeat",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": " ",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 639,
                                                                            "char": 47
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 639,
                                                                        "char": 47
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "paddingSize",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 639,
                                                                            "char": 60
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 639,
                                                                        "char": 60
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 639,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 639,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 640,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 642,
                                                    "char": 23
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 642,
                                            "char": 23
                                        },
                                        {
                                            "type": "default",
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "paddingSize",
                                                            "expr": {
                                                                "type": "int",
                                                                "value": "0",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 643,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 643,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 644,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 645,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 645,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 646,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 648,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "paddingSize",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 648,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 648,
                                "char": 25
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "text",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 649,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 650,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 652,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "greater",
                                    "left": {
                                        "type": "variable",
                                        "value": "paddingSize",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 652,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "blockSize",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 652,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 652,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 652,
                                "char": 45
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
                                                    "value": "Invalid padding size",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 653,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 653,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 653,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 654,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 656,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "variable",
                                    "value": "text",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 656,
                                    "char": 21
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "substr",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "padding",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 656,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 656,
                                            "char": 37
                                        },
                                        {
                                            "parameter": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 656,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 656,
                                            "char": 40
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "paddingSize",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 656,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 656,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 656,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 656,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 657,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Pads texts before encryption. See [cryptopad](http:\/\/www.di-mgt.com.au\/cryptopad.html)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 598,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 598,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 597,
                    "last-line": 664,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "cryptUnpadText",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 665,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "mode",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 665,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "blockSize",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 665,
                            "char": 80
                        },
                        {
                            "type": "parameter",
                            "name": "paddingType",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 665,
                            "char": 98
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "padding",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 667,
                                    "char": 20
                                },
                                {
                                    "variable": "last",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 667,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 668,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "long",
                            "variables": [
                                {
                                    "variable": "length",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 668,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 669,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "i",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 669,
                                    "char": 14
                                },
                                {
                                    "variable": "paddingSize",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 669,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 669,
                                    "char": 31
                                },
                                {
                                    "variable": "ord",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 669,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 671,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "length",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strlen",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 671,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 671,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 671,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 671,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 673,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "and",
                                    "left": {
                                        "type": "greater",
                                        "left": {
                                            "type": "variable",
                                            "value": "length",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 673,
                                            "char": 19
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 673,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 673,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "list",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "mod",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "length",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 673,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "blockSize",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 673,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 673,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 673,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 673,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 673,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 673,
                                    "char": 53
                                },
                                "right": {
                                    "type": "list",
                                    "left": {
                                        "type": "or",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "mode",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 673,
                                                "char": 62
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "cbc",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 673,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 673,
                                            "char": 69
                                        },
                                        "right": {
                                            "type": "equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "mode",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 673,
                                                "char": 77
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "ecb",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 673,
                                                "char": 82
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 673,
                                            "char": 82
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 673,
                                        "char": 82
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 673,
                                    "char": 84
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 673,
                                "char": 84
                            },
                            "statements": [
                                {
                                    "type": "switch",
                                    "expr": {
                                        "type": "variable",
                                        "value": "paddingType",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 674,
                                        "char": 32
                                    },
                                    "clauses": [
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 676,
                                                    "char": 46
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PADDING_ANSI_X_923",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 676,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 676,
                                                "char": 46
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "last",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "substr",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "text",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 677,
                                                                            "char": 43
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 677,
                                                                        "char": 43
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "sub",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "length",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 677,
                                                                                "char": 52
                                                                            },
                                                                            "right": {
                                                                                "type": "int",
                                                                                "value": "1",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 677,
                                                                                "char": 55
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 677,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 677,
                                                                        "char": 55
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "int",
                                                                            "value": "1",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 677,
                                                                            "char": 58
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 677,
                                                                        "char": 58
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 677,
                                                                "char": 59
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 677,
                                                            "char": 59
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 678,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "ord",
                                                            "expr": {
                                                                "type": "cast",
                                                                "left": "int",
                                                                "right": {
                                                                    "type": "fcall",
                                                                    "name": "ord",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "last",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 678,
                                                                                "char": 45
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 678,
                                                                            "char": 45
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 678,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 678,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 678,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 680,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "less-equal",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "ord",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 680,
                                                            "char": 28
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "blockSize",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 680,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 680,
                                                        "char": 40
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "paddingSize",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "ord",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 681,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 681,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 682,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "padding",
                                                                    "expr": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "fcall",
                                                                            "name": "str_repeat",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "fcall",
                                                                                        "name": "chr",
                                                                                        "call-type": 1,
                                                                                        "parameters": [
                                                                                            {
                                                                                                "parameter": {
                                                                                                    "type": "int",
                                                                                                    "value": "0",
                                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                                    "line": 682,
                                                                                                    "char": 55
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                                "line": 682,
                                                                                                "char": 55
                                                                                            }
                                                                                        ],
                                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                                        "line": 682,
                                                                                        "char": 56
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 682,
                                                                                    "char": 56
                                                                                },
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "sub",
                                                                                        "left": {
                                                                                            "type": "variable",
                                                                                            "value": "paddingSize",
                                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                                            "line": 682,
                                                                                            "char": 70
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "int",
                                                                                            "value": "1",
                                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                                            "line": 682,
                                                                                            "char": 73
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                                        "line": 682,
                                                                                        "char": 73
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 682,
                                                                                    "char": 73
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 682,
                                                                            "char": 75
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "last",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 682,
                                                                            "char": 81
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 682,
                                                                        "char": 81
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 682,
                                                                    "char": 81
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 684,
                                                            "char": 26
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "not-equals",
                                                                "left": {
                                                                    "type": "fcall",
                                                                    "name": "substr",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "text",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 684,
                                                                                "char": 39
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 684,
                                                                            "char": 39
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "sub",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "length",
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 684,
                                                                                    "char": 48
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "paddingSize",
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 684,
                                                                                    "char": 61
                                                                                },
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 684,
                                                                                "char": 61
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 684,
                                                                            "char": 61
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 684,
                                                                    "char": 64
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "padding",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 684,
                                                                    "char": 74
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 684,
                                                                "char": 74
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "paddingSize",
                                                                            "expr": {
                                                                                "type": "int",
                                                                                "value": "0",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 685,
                                                                                "char": 48
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 685,
                                                                            "char": 48
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 686,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 687,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 689,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 691,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 691,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 691,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PADDING_PKCS7",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 691,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 691,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "last",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "substr",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "text",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 692,
                                                                            "char": 43
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 692,
                                                                        "char": 43
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "sub",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "length",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 692,
                                                                                "char": 52
                                                                            },
                                                                            "right": {
                                                                                "type": "int",
                                                                                "value": "1",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 692,
                                                                                "char": 55
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 692,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 692,
                                                                        "char": 55
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "int",
                                                                            "value": "1",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 692,
                                                                            "char": 58
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 692,
                                                                        "char": 58
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 692,
                                                                "char": 59
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 692,
                                                            "char": 59
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 693,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "ord",
                                                            "expr": {
                                                                "type": "cast",
                                                                "left": "int",
                                                                "right": {
                                                                    "type": "fcall",
                                                                    "name": "ord",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "last",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 693,
                                                                                "char": 45
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 693,
                                                                            "char": 45
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 693,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 693,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 693,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 695,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "less-equal",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "ord",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 695,
                                                            "char": 28
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "blockSize",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 695,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 695,
                                                        "char": 40
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "paddingSize",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "ord",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 696,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 696,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 697,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "padding",
                                                                    "expr": {
                                                                        "type": "fcall",
                                                                        "name": "str_repeat",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "fcall",
                                                                                    "name": "chr",
                                                                                    "call-type": 1,
                                                                                    "parameters": [
                                                                                        {
                                                                                            "parameter": {
                                                                                                "type": "variable",
                                                                                                "value": "paddingSize",
                                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                                "line": 697,
                                                                                                "char": 65
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                                            "line": 697,
                                                                                            "char": 65
                                                                                        }
                                                                                    ],
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 697,
                                                                                    "char": 66
                                                                                },
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 697,
                                                                                "char": 66
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "paddingSize",
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 697,
                                                                                    "char": 79
                                                                                },
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 697,
                                                                                "char": 79
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 697,
                                                                        "char": 80
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 697,
                                                                    "char": 80
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 699,
                                                            "char": 26
                                                        },
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "not-equals",
                                                                "left": {
                                                                    "type": "fcall",
                                                                    "name": "substr",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "text",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 699,
                                                                                "char": 39
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 699,
                                                                            "char": 39
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "sub",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "length",
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 699,
                                                                                    "char": 48
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "paddingSize",
                                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                                    "line": 699,
                                                                                    "char": 61
                                                                                },
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 699,
                                                                                "char": 61
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 699,
                                                                            "char": 61
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 699,
                                                                    "char": 64
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "padding",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 699,
                                                                    "char": 74
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 699,
                                                                "char": 74
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "paddingSize",
                                                                            "expr": {
                                                                                "type": "int",
                                                                                "value": "0",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 700,
                                                                                "char": 48
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 700,
                                                                            "char": 48
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 701,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 702,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 704,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 706,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 706,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 706,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PADDING_ISO_10126",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 706,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 706,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "last",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "substr",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "text",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 707,
                                                                            "char": 43
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 707,
                                                                        "char": 43
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "sub",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "length",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 707,
                                                                                "char": 52
                                                                            },
                                                                            "right": {
                                                                                "type": "int",
                                                                                "value": "1",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 707,
                                                                                "char": 55
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 707,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 707,
                                                                        "char": 55
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "int",
                                                                            "value": "1",
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 707,
                                                                            "char": 58
                                                                        },
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 707,
                                                                        "char": 58
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 707,
                                                                "char": 59
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 707,
                                                            "char": 59
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 708,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "paddingSize",
                                                            "expr": {
                                                                "type": "cast",
                                                                "left": "int",
                                                                "right": {
                                                                    "type": "fcall",
                                                                    "name": "ord",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "last",
                                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                                "line": 708,
                                                                                "char": 53
                                                                            },
                                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                                            "line": 708,
                                                                            "char": 53
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 708,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 708,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 708,
                                                            "char": 54
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 709,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 711,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 711,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 711,
                                                    "char": 50
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PADDING_ISO_IEC_7816_4",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 711,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 711,
                                                "char": 50
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "i",
                                                            "expr": {
                                                                "type": "sub",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "length",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 712,
                                                                    "char": 36
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 712,
                                                                    "char": 39
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 712,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 712,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 714,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "while",
                                                    "expr": {
                                                        "type": "and",
                                                        "left": {
                                                            "type": "and",
                                                            "left": {
                                                                "type": "greater",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "i",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 714,
                                                                    "char": 29
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 714,
                                                                    "char": 34
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 714,
                                                                "char": 34
                                                            },
                                                            "right": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "text",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 714,
                                                                        "char": 40
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "i",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 714,
                                                                        "char": 42
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 714,
                                                                    "char": 45
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0x00",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 714,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 714,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 714,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "less",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "paddingSize",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 714,
                                                                "char": 67
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "blockSize",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 714,
                                                                "char": 79
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 714,
                                                            "char": 79
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 714,
                                                        "char": 79
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "incr",
                                                                    "variable": "paddingSize",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 715,
                                                                    "char": 42
                                                                },
                                                                {
                                                                    "assign-type": "decr",
                                                                    "variable": "i",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 716,
                                                                    "char": 32
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 717,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 719,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "text",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 719,
                                                                "char": 28
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "i",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 719,
                                                                "char": 30
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 719,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0x80",
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 719,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 719,
                                                        "char": 40
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "incr",
                                                                    "variable": "paddingSize",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 720,
                                                                    "char": 42
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 721,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "paddingSize",
                                                                    "expr": {
                                                                        "type": "int",
                                                                        "value": "0",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 722,
                                                                        "char": 44
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 722,
                                                                    "char": 44
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 723,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 725,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 727,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 727,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 727,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PADDING_ZERO",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 727,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 727,
                                                "char": 40
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "i",
                                                            "expr": {
                                                                "type": "sub",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "length",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 728,
                                                                    "char": 36
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 728,
                                                                    "char": 39
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 728,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 728,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 730,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "while",
                                                    "expr": {
                                                        "type": "and",
                                                        "left": {
                                                            "type": "and",
                                                            "left": {
                                                                "type": "greater-equal",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "i",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 730,
                                                                    "char": 29
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 730,
                                                                    "char": 34
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 730,
                                                                "char": 34
                                                            },
                                                            "right": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "text",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 730,
                                                                        "char": 40
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "i",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 730,
                                                                        "char": 42
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 730,
                                                                    "char": 45
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0x00",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 730,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 730,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 730,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "less-equal",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "paddingSize",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 730,
                                                                "char": 67
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "blockSize",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 730,
                                                                "char": 79
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 730,
                                                            "char": 79
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 730,
                                                        "char": 79
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "incr",
                                                                    "variable": "paddingSize",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 731,
                                                                    "char": 42
                                                                },
                                                                {
                                                                    "assign-type": "decr",
                                                                    "variable": "i",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 732,
                                                                    "char": 32
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 733,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 735,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 737,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 737,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 737,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "PADDING_SPACE",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 737,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 737,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "i",
                                                            "expr": {
                                                                "type": "sub",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "length",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 738,
                                                                    "char": 36
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 738,
                                                                    "char": 39
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 738,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 738,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 740,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "while",
                                                    "expr": {
                                                        "type": "and",
                                                        "left": {
                                                            "type": "and",
                                                            "left": {
                                                                "type": "greater-equal",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "i",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 740,
                                                                    "char": 29
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 740,
                                                                    "char": 34
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 740,
                                                                "char": 34
                                                            },
                                                            "right": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "text",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 740,
                                                                        "char": 40
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "i",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 740,
                                                                        "char": 42
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 740,
                                                                    "char": 45
                                                                },
                                                                "right": {
                                                                    "type": "int",
                                                                    "value": "0x20",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 740,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 740,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 740,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "less-equal",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "paddingSize",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 740,
                                                                "char": 67
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "blockSize",
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 740,
                                                                "char": 79
                                                            },
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 740,
                                                            "char": 79
                                                        },
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 740,
                                                        "char": 79
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "incr",
                                                                    "variable": "paddingSize",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 741,
                                                                    "char": 42
                                                                },
                                                                {
                                                                    "assign-type": "decr",
                                                                    "variable": "i",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 742,
                                                                    "char": 32
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Crypt.zep",
                                                            "line": 743,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 745,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 747,
                                                    "char": 23
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 747,
                                            "char": 23
                                        },
                                        {
                                            "type": "default",
                                            "statements": [
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 749,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 749,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 751,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "variable",
                                            "value": "paddingSize",
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 751,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "less-equal",
                                            "left": {
                                                "type": "variable",
                                                "value": "paddingSize",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 751,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "blockSize",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 751,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 751,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 751,
                                        "char": 55
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "less",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "paddingSize",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 752,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "length",
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 752,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 752,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "substr",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "text",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 753,
                                                                    "char": 39
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 753,
                                                                "char": 39
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 753,
                                                                    "char": 42
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 753,
                                                                "char": 42
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "sub",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "length",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 753,
                                                                        "char": 51
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "paddingSize",
                                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                                        "line": 753,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                                    "line": 753,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                                "line": 753,
                                                                "char": 64
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 753,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 754,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 756,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Crypt.zep",
                                                "line": 756,
                                                "char": 24
                                            },
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 757,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "paddingSize",
                                                    "expr": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Crypt.zep",
                                                        "line": 758,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Crypt.zep",
                                                    "line": 758,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Crypt.zep",
                                            "line": 759,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 761,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 763,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "paddingSize",
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 763,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Crypt.zep",
                                "line": 763,
                                "char": 25
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "text",
                                        "file": "\/app\/phalcon\/Crypt.zep",
                                        "line": 764,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Crypt.zep",
                                    "line": 765,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Crypt.zep",
                            "line": 766,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes a padding from a text.\n     *\n     * If the function detects that the text was not padded, it will return it\n     * unmodified.\n     *",
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 665,
                    "last-line": 767,
                    "char": 22
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "PADDING_ANSI_X_923",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 37,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 38,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PADDING_DEFAULT",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 38,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 39,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PADDING_ISO_10126",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 39,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 40,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PADDING_ISO_IEC_7816_4",
                    "default": {
                        "type": "int",
                        "value": "4",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 40,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 41,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PADDING_PKCS7",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 41,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 42,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PADDING_SPACE",
                    "default": {
                        "type": "int",
                        "value": "6",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 42,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 43,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PADDING_ZERO",
                    "default": {
                        "type": "int",
                        "value": "5",
                        "file": "\/app\/phalcon\/Crypt.zep",
                        "line": 43,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Crypt.zep",
                    "line": 47,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Crypt.zep",
            "line": 35,
            "char": 5
        },
        "file": "\/app\/phalcon\/Crypt.zep",
        "line": 35,
        "char": 5
    }
]