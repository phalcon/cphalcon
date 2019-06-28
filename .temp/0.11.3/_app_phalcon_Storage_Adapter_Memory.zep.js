[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Adapter",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection\\Collection",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                "line": 13,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                "line": 14,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                "line": 15,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Exception",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                "line": 16,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\SerializerFactory",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                "line": 17,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                "line": 18,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Storage\\Adapter\\Memory\n *\n * Memory adapter\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
        "line": 25,
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
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                        "line": 30,
                        "char": 24
                    },
                    "docblock": "**\n     * @var Collection\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                    "line": 34,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "options",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                        "line": 35,
                        "char": 27
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                    "line": 39,
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
                            "name": "factory",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "SerializerFactory",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 40,
                                "char": 59
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 40,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 40,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 40,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 40,
                            "char": 88
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
                                    "property": "prefix",
                                    "expr": {
                                        "type": "string",
                                        "value": "ph-memo-",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 45,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 45,
                                    "char": 37
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 46,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 46,
                                    "char": 36
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "data",
                                    "expr": {
                                        "type": "new",
                                        "class": "Collection",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 47,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 47,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 49,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "__construct",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "factory",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 49,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 49,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 49,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 49,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 49,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 51,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 51,
                                    "char": 14
                                },
                                "name": "initSerializer",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 51,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 52,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                    "line": 40,
                    "last-line": 56,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "clear",
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 59,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 59,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 59,
                                    "char": 20
                                },
                                "name": "clear",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 59,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 61,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 61,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 62,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Flushes\/clears the cache\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 58,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                        "line": 58,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                    "line": 57,
                    "last-line": 71,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "decrement",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 72,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "1",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 72,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 72,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "current",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 74,
                                    "char": 20
                                },
                                {
                                    "variable": "newValue",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 74,
                                    "char": 30
                                },
                                {
                                    "variable": "prefixedKey",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 74,
                                    "char": 43
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 74,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 76,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "prefixedKey",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 76,
                                            "char": 32
                                        },
                                        "name": "getPrefixedKey",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 76,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 76,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 76,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 76,
                                    "char": 52
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 77,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 77,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 77,
                                            "char": 38
                                        },
                                        "name": "has",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "prefixedKey",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 77,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 77,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 77,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 77,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 79,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 79,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "current",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                        "line": 80,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                        "line": 80,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 80,
                                                    "char": 39
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "prefixedKey",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                            "line": 80,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                        "line": 80,
                                                        "char": 55
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 80,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 80,
                                            "char": 56
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "newValue",
                                            "expr": {
                                                "type": "sub",
                                                "left": {
                                                    "type": "cast",
                                                    "left": "int",
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "current",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                        "line": 81,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 81,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 81,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 81,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 81,
                                            "char": 49
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "result",
                                            "expr": {
                                                "type": "variable",
                                                "value": "newValue",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 82,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 82,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 84,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 84,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 84,
                                                "char": 24
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 84,
                                            "char": 24
                                        },
                                        "name": "set",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "prefixedKey",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 84,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 84,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "newValue",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 84,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 84,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 84,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 85,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 87,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 87,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 88,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Decrements a stored number\n     *\n     * @param string $key\n     * @param int    $value\n     *\n     * @return bool|int\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 72,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 73,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                        "line": 73,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                    "line": 72,
                    "last-line": 96,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 97,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "exists",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 99,
                                    "char": 19
                                },
                                {
                                    "variable": "prefixedKey",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 99,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 101,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "prefixedKey",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 101,
                                            "char": 32
                                        },
                                        "name": "getPrefixedKey",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 101,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 101,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 101,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 101,
                                    "char": 52
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "exists",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 102,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 102,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 102,
                                            "char": 38
                                        },
                                        "name": "has",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "prefixedKey",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 102,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 102,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 102,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 102,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 104,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 104,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 104,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 104,
                                    "char": 20
                                },
                                "name": "remove",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "prefixedKey",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 104,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 104,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 104,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 106,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "exists",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 106,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 107,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads data from the adapter\n     *\n     * @param string $key\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 98,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                        "line": 98,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                    "line": 97,
                    "last-line": 116,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 117,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 117,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 117,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "content",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 119,
                                    "char": 20
                                },
                                {
                                    "variable": "prefixedKey",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 119,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 121,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "prefixedKey",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 121,
                                            "char": 32
                                        },
                                        "name": "getPrefixedKey",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 121,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 121,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 121,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 121,
                                    "char": 52
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "content",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 122,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 122,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 122,
                                            "char": 38
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "prefixedKey",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 122,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 122,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 122,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 122,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 124,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 124,
                                    "char": 21
                                },
                                "name": "getUnserializedData",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "content",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 124,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 124,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "defaultValue",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 124,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 124,
                                        "char": 63
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 124,
                                "char": 64
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 125,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads data from the adapter\n     *\n     * @param string     $key\n     * @param mixed|null $defaultValue\n     *\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 118,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                        "line": 118,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                    "line": 117,
                    "last-line": 132,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAdapter",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 135,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "adapter",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 135,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 135,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 136,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the already connected adapter or connects to the Memcached\n     * server(s)\n     *\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 134,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                        "line": 134,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                    "line": 133,
                    "last-line": 142,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getKeys",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "array_keys",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 145,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 145,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 145,
                                                "char": 38
                                            },
                                            "name": "toArray",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 145,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 145,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 145,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 146,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Stores data in the adapter\n     *\n     * @return array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 144,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                        "line": 144,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                    "line": 143,
                    "last-line": 154,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 155,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "prefixedKey",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 157,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 159,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "prefixedKey",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 159,
                                            "char": 32
                                        },
                                        "name": "getPrefixedKey",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 159,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 159,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 159,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 159,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 161,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 161,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 161,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 161,
                                    "char": 27
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "prefixedKey",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 161,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 161,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 161,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 162,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if an element exists in the cache\n     *\n     * @param string $key\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 156,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                        "line": 156,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                    "line": 155,
                    "last-line": 171,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "increment",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 172,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "1",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 172,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 172,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "current",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 174,
                                    "char": 20
                                },
                                {
                                    "variable": "newValue",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 174,
                                    "char": 30
                                },
                                {
                                    "variable": "prefixedKey",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 174,
                                    "char": 43
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 174,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 176,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "prefixedKey",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 176,
                                            "char": 32
                                        },
                                        "name": "getPrefixedKey",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 176,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 176,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 176,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 176,
                                    "char": 52
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 177,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 177,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 177,
                                            "char": 38
                                        },
                                        "name": "has",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "prefixedKey",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 177,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 177,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 177,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 177,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 179,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 179,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "current",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                        "line": 180,
                                                        "char": 33
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                        "line": 180,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 180,
                                                    "char": 39
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "prefixedKey",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                            "line": 180,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                        "line": 180,
                                                        "char": 55
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 180,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 180,
                                            "char": 56
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "newValue",
                                            "expr": {
                                                "type": "add",
                                                "left": {
                                                    "type": "cast",
                                                    "left": "int",
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "current",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                        "line": 181,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 181,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 181,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 181,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 181,
                                            "char": 49
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "result",
                                            "expr": {
                                                "type": "variable",
                                                "value": "newValue",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 182,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 182,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 184,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 184,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 184,
                                                "char": 24
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 184,
                                            "char": 24
                                        },
                                        "name": "set",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "prefixedKey",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 184,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 184,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "newValue",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 184,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 184,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 184,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 185,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 187,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 187,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 188,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Increments a stored number\n     *\n     * @param string $key\n     * @param int    $value\n     *\n     * @return bool|int\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 172,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 173,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                        "line": 173,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                    "line": 172,
                    "last-line": 198,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 199,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 199,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "ttl",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 199,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 199,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "content",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 201,
                                    "char": 20
                                },
                                {
                                    "variable": "lifetime",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 201,
                                    "char": 30
                                },
                                {
                                    "variable": "prefixedKey",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 201,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 203,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "content",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 203,
                                            "char": 32
                                        },
                                        "name": "getSerializedData",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 203,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 203,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 203,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 203,
                                    "char": 57
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "lifetime",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 204,
                                            "char": 32
                                        },
                                        "name": "getTtl",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ttl",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 204,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 204,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 204,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 204,
                                    "char": 44
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "prefixedKey",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 205,
                                            "char": 32
                                        },
                                        "name": "getPrefixedKey",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                    "line": 205,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                                "line": 205,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 205,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 205,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 207,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 207,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 207,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                    "line": 207,
                                    "char": 20
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "prefixedKey",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 207,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 207,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "content",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                            "line": 207,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                        "line": 207,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 207,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 209,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 209,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                            "line": 210,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Stores data in the adapter\n     *\n     * @param string $key\n     * @param mixed  $value\n     * @param null   $ttl\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                                "line": 200,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                        "line": 200,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
                    "line": 199,
                    "last-line": 211,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
            "line": 25,
            "char": 5
        },
        "file": "\/app\/phalcon\/Storage\/Adapter\/Memory.zep",
        "line": 25,
        "char": 5
    }
]