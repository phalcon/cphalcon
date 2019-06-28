[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Filter",
        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Filter\\Filter",
                "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
        "line": 15,
        "char": 5
    },
    {
        "type": "class",
        "name": "FilterFactory",
        "abstract": 0,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "newInstance",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "Filter",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                                "line": 24,
                                                "char": 18
                                            },
                                            "name": "getAdapters",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 25,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 25,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                "line": 25,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                            "line": 26,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a Locator object with all the helpers defined in anonynous\n     * functions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "LocatorInterface",
                                    "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                    "line": 22,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                "line": 22,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                        "line": 22,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                    "line": 21,
                    "last-line": 28,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getAdapters",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "absint",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 31,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\AbsInt",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 31,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 31,
                                        "char": 62
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "alnum",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 32,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Alnum",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 32,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 32,
                                        "char": 61
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "alpha",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 33,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Alpha",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 33,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 33,
                                        "char": 61
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "bool",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 34,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\BoolVal",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 34,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 34,
                                        "char": 63
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "email",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 35,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Email",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 35,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 35,
                                        "char": 61
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "float",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 36,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\FloatVal",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 36,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 36,
                                        "char": 64
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "int",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 37,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\IntVal",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 37,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 37,
                                        "char": 62
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "lower",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 38,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Lower",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 38,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 38,
                                        "char": 61
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "lowerFirst",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 39,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\LowerFirst",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 39,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 39,
                                        "char": 66
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "regex",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 40,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Regex",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 40,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 40,
                                        "char": 61
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "remove",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 41,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Remove",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 41,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 41,
                                        "char": 62
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "replace",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 42,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Replace",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 42,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 42,
                                        "char": 63
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "special",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 43,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Special",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 43,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 43,
                                        "char": 63
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "specialFull",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 44,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\SpecialFull",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 44,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 44,
                                        "char": 67
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "string",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 45,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\StringVal",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 45,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 45,
                                        "char": 65
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "striptags",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 46,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Striptags",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 46,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 46,
                                        "char": 65
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "trim",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 47,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Trim",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 47,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 47,
                                        "char": 60
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "upper",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 48,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Upper",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 48,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 48,
                                        "char": 61
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "upperFirst",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 49,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\UpperFirst",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 49,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 49,
                                        "char": 66
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "upperWords",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 50,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\UpperWords",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 50,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 50,
                                        "char": 66
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "url",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 51,
                                            "char": 25
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Filter\\\\Sanitize\\\\Url",
                                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                            "line": 52,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                        "line": 52,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                "line": 52,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                            "line": 53,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                                "line": 29,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                        "line": 29,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
                    "line": 28,
                    "last-line": 54,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
            "line": 15,
            "char": 5
        },
        "file": "\/app\/phalcon\/Filter\/FilterFactory.zep",
        "line": 15,
        "char": 5
    }
]