[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Response",
        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\CookieInterface",
                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                "line": 13,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Http\\Response\\CookiesInterface\n *\n * Interface for Phalcon\\Http\\Response\\Cookies\n *",
        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "CookiesInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                            "line": 26,
                            "char": 40
                        }
                    ],
                    "docblock": "**\n     * Deletes a cookie by its name\n     * This method does not removes cookies from the _COOKIE superglobal\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 26,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                        "line": 26,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                    "line": 26,
                    "last-line": 30,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                            "line": 31,
                            "char": 37
                        }
                    ],
                    "docblock": "**\n     * Gets a cookie from the bag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookieInterface",
                                    "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                    "line": 31,
                                    "char": 59
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 31,
                                "char": 59
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                        "line": 31,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                    "line": 31,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "has",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                            "line": 36,
                            "char": 37
                        }
                    ],
                    "docblock": "**\n     * Check if a cookie is defined in the bag or exists in the _COOKIE superglobal\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 36,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                        "line": 36,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                    "line": 36,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isUsingEncryption",
                    "docblock": "**\n     * Returns if the bag is automatically encrypting\/decrypting cookies\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 41,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                        "line": 41,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                    "line": 41,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "reset",
                    "docblock": "**\n     * Reset set cookies\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookiesInterface",
                                    "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                    "line": 46,
                                    "char": 50
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 46,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                        "line": 46,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                    "line": 46,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "send",
                    "docblock": "**\n     * Sends the cookies to the client\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 51,
                                "char": 35
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                        "line": 51,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                    "line": 51,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "set",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                            "line": 56,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 56,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                            "line": 56,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "expire",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 56,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                            "line": 56,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "\/",
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 56,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                            "line": 56,
                            "char": 84
                        },
                        {
                            "type": "parameter",
                            "name": "secure",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 56,
                                "char": 104
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                            "line": 56,
                            "char": 104
                        },
                        {
                            "type": "parameter",
                            "name": "domain",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 56,
                                "char": 127
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                            "line": 56,
                            "char": 127
                        },
                        {
                            "type": "parameter",
                            "name": "httpOnly",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 56,
                                "char": 149
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                            "line": 56,
                            "char": 149
                        }
                    ],
                    "docblock": "**\n     * Sets a cookie to be sent at the end of the request\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookiesInterface",
                                    "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                    "line": 56,
                                    "char": 172
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 56,
                                "char": 172
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                        "line": 56,
                        "char": 172
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                    "line": 56,
                    "last-line": 60,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "useEncryption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "useEncryption",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                            "line": 61,
                            "char": 53
                        }
                    ],
                    "docblock": "**\n     * Set if cookies in the bag must be automatically encrypted\/decrypted\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CookiesInterface",
                                    "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                    "line": 61,
                                    "char": 76
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                                "line": 61,
                                "char": 76
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                        "line": 61,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
                    "line": 61,
                    "last-line": 62,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
            "line": 62,
            "char": 1
        },
        "file": "\/app\/phalcon\/Http\/Response\/CookiesInterface.zep",
        "line": 0,
        "char": 0
    }
]