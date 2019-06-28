[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Annotations\\Adapter",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                "line": 13,
                "char": 48
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Reflection",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                "line": 14,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Stores the parsed annotations in memory. This adapter is the suitable\n * development\/testing\n *",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Memory",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractAdapter",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "data",
                    "docblock": "**\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                    "line": 29,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "read",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                            "line": 30,
                            "char": 37
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                    "line": 32,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                            "line": 34,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                        "line": 34,
                                        "char": 53
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                                "line": 34,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                                "line": 34,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                            "line": 34,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "strtolower",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                                        "line": 34,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                                    "line": 34,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                            "line": 34,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                        "line": 34,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                    "line": 34,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                "line": 34,
                                "char": 53
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                        "line": 35,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                    "line": 36,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                            "line": 38,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                "line": 38,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                            "line": 39,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads parsed annotations from memory\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Reflection",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                    "line": 30,
                                    "char": 55
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                "line": 30,
                                "char": 55
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                "line": 31,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                        "line": 31,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                    "line": 30,
                    "last-line": 43,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "write",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                            "line": 44,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Reflection",
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                "line": 44,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                            "line": 44,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "lowercasedKey",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                    "line": 46,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                            "line": 48,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "lowercasedKey",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtolower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                                    "line": 48,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                                "line": 48,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                        "line": 48,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                    "line": 48,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                            "line": 49,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "data",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "lowercasedKey",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                            "line": 49,
                                            "char": 37
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                        "line": 49,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                                    "line": 49,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                            "line": 50,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Writes parsed annotations to memory\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                        "line": 45,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
                    "line": 44,
                    "last-line": 51,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Memory.zep",
        "line": 20,
        "char": 5
    }
]