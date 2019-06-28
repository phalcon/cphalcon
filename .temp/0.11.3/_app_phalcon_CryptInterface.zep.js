[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/CryptInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/CryptInterface.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Crypt\n *",
        "file": "\/app\/phalcon\/CryptInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "CryptInterface",
        "definition": {
            "methods": [
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
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 21,
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
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 21,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 21,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Decrypts a text\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 21,
                                "char": 72
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 21,
                        "char": 72
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 21,
                    "last-line": 25,
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
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 26,
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
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 26,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 26,
                            "char": 59
                        }
                    ],
                    "docblock": "**\n     * Decrypt a text that is coded as a base64 string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 26,
                                "char": 70
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 26,
                        "char": 70
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 26,
                    "last-line": 30,
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
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 31,
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
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 31,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 31,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Encrypts a text\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 31,
                                "char": 72
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 31,
                        "char": 72
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 31,
                    "last-line": 35,
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
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 36,
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
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 36,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 36,
                            "char": 59
                        }
                    ],
                    "docblock": "**\n     * Encrypts a text returning the result as a base64 string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 36,
                                "char": 70
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 36,
                        "char": 70
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 36,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAvailableCiphers",
                    "docblock": "**\n     * Returns a list of available cyphers\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 41,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 41,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 41,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAuthTag",
                    "docblock": "**\n     * Returns the authentication tag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 46,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 46,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 46,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAuthData",
                    "docblock": "**\n     * Returns authentication data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 51,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 51,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 51,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAuthTagLength",
                    "docblock": "**\n     * Returns the authentication tag length\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 56,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 56,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 56,
                    "last-line": 60,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCipher",
                    "docblock": "**\n     * Returns the current cipher\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 61,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 61,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 61,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getKey",
                    "docblock": "**\n     * Returns the encryption key\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 66,
                                "char": 39
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 66,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 66,
                    "last-line": 70,
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
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 71,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Sets the authentication tag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/CryptInterface.zep",
                                    "line": 71,
                                    "char": 64
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 71,
                                "char": 64
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 71,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 71,
                    "last-line": 75,
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
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 76,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Sets authentication data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/CryptInterface.zep",
                                    "line": 76,
                                    "char": 66
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 76,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 76,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 76,
                    "last-line": 80,
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
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 81,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Sets the authentication tag length\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/CryptInterface.zep",
                                    "line": 81,
                                    "char": 70
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 81,
                                "char": 70
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 81,
                        "char": 70
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 81,
                    "last-line": 85,
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
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 86,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Sets the cipher algorithm\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/CryptInterface.zep",
                                    "line": 86,
                                    "char": 66
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 86,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 86,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 86,
                    "last-line": 90,
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
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 91,
                            "char": 39
                        }
                    ],
                    "docblock": "**\n     * Sets the encryption key\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CryptInterface",
                                    "file": "\/app\/phalcon\/CryptInterface.zep",
                                    "line": 91,
                                    "char": 60
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 91,
                                "char": 60
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 91,
                        "char": 60
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 91,
                    "last-line": 95,
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
                            "file": "\/app\/phalcon\/CryptInterface.zep",
                            "line": 96,
                            "char": 43
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
                                    "file": "\/app\/phalcon\/CryptInterface.zep",
                                    "line": 96,
                                    "char": 64
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/CryptInterface.zep",
                                "line": 96,
                                "char": 64
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/CryptInterface.zep",
                        "line": 96,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/CryptInterface.zep",
                    "line": 96,
                    "last-line": 97,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/CryptInterface.zep",
            "line": 97,
            "char": 1
        },
        "file": "\/app\/phalcon\/CryptInterface.zep",
        "line": 0,
        "char": 0
    }
]