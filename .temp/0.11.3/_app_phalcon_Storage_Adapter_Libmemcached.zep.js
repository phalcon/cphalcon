[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Adapter",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                "line": 14,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Exception",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                "line": 15,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\SerializerFactory",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                "line": 16,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                "line": 17,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
        "line": 23,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Storage\\Adapter\\Libmemcached\n *\n * Libmemcached adapter\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
        "line": 24,
        "char": 5
    },
    {
        "type": "class",
        "name": "Libmemcached",
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
                    "name": "options",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                        "line": 29,
                        "char": 27
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                    "line": 35,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 36,
                                "char": 59
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 36,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 36,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 36,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 36,
                            "char": 88
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 38,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "servers",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 38,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 38,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 38,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 38,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "options",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "servers",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 39,
                                                    "char": 32
                                                }
                                            ],
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                            "line": 40,
                                                            "char": 18
                                                        },
                                                        "value": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "host",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 41,
                                                                        "char": 28
                                                                    },
                                                                    "value": {
                                                                        "type": "string",
                                                                        "value": "127.0.0.1",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 41,
                                                                        "char": 39
                                                                    },
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 41,
                                                                    "char": 39
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "port",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 42,
                                                                        "char": 28
                                                                    },
                                                                    "value": {
                                                                        "type": "int",
                                                                        "value": "11211",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 42,
                                                                        "char": 35
                                                                    },
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 42,
                                                                    "char": 35
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "weight",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 43,
                                                                        "char": 28
                                                                    },
                                                                    "value": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 44,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 44,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                            "line": 45,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 45,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 45,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 45,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 46,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 48,
                            "char": 11
                        },
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
                                        "value": "ph-memc-",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 48,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 48,
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
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 49,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 49,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 51,
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
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 51,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 51,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 51,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 51,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 51,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 52,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Libmemcached constructor.\n     *\n     * @param array $options\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                    "line": 36,
                    "last-line": 59,
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
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 62,
                                        "char": 21
                                    },
                                    "name": "getAdapter",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 62,
                                    "char": 35
                                },
                                "name": "flush",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 62,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 63,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Flushes\/clears the cache\n     *\n     * @return bool\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 61,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                        "line": 61,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                    "line": 60,
                    "last-line": 67,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 68,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 68,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 68,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 70,
                                        "char": 21
                                    },
                                    "name": "getAdapter",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 70,
                                    "char": 35
                                },
                                "name": "decrement",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 70,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 70,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 70,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 70,
                                        "char": 56
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 70,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 71,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Decrements a stored number\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 68,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 69,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                        "line": 69,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                    "line": 68,
                    "last-line": 80,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 81,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 83,
                                        "char": 21
                                    },
                                    "name": "getAdapter",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 83,
                                    "char": 35
                                },
                                "name": "delete",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 83,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 83,
                                        "char": 46
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 83,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 83,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 83,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 84,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads data from the adapter\n     *\n     * @param string $key\n     *\n     * @return bool\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 82,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                        "line": 82,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                    "line": 81,
                    "last-line": 94,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 95,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 95,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 95,
                            "char": 61
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
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 97,
                                    "char": 21
                                },
                                "name": "getUnserializedData",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 98,
                                                    "char": 18
                                                },
                                                "name": "getAdapter",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 98,
                                                "char": 32
                                            },
                                            "name": "get",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 98,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 98,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 98,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 98,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "defaultValue",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 100,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 100,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 100,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 101,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads data from the adapter\n     *\n     * @param string $key\n     * @param null   $defaultValue\n     *\n     * @return mixed\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 96,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                        "line": 96,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                    "line": 95,
                    "last-line": 109,
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
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "client",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 112,
                                    "char": 19
                                },
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 112,
                                    "char": 31
                                },
                                {
                                    "variable": "failover",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 112,
                                    "char": 41
                                },
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 112,
                                    "char": 50
                                },
                                {
                                    "variable": "persistentId",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 112,
                                    "char": 64
                                },
                                {
                                    "variable": "sasl",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 113,
                                    "char": 17
                                },
                                {
                                    "variable": "saslPass",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 113,
                                    "char": 27
                                },
                                {
                                    "variable": "saslUser",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 113,
                                    "char": 37
                                },
                                {
                                    "variable": "servers",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 113,
                                    "char": 46
                                },
                                {
                                    "variable": "serverList",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 113,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 115,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 115,
                                    "char": 19
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 115,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 115,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 115,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 115,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "options",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 116,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 116,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 116,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 116,
                                            "char": 45
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "persistentId",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "Arr",
                                                "dynamic": 0,
                                                "name": "get",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                            "line": 117,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 117,
                                                        "char": 48
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "persistentId",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                            "line": 117,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 117,
                                                        "char": 62
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "ph-mcid-",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                            "line": 117,
                                                            "char": 72
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 117,
                                                        "char": 72
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 117,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 117,
                                            "char": 73
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "sasl",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "Arr",
                                                "dynamic": 0,
                                                "name": "get",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                            "line": 118,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 118,
                                                        "char": 48
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "saslAuthData",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                            "line": 118,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 118,
                                                        "char": 62
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "empty-array",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                            "line": 118,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 118,
                                                        "char": 66
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 118,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 118,
                                            "char": 67
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "connection",
                                            "expr": {
                                                "type": "new",
                                                "class": "\\Memcached",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "persistentId",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                            "line": 119,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 119,
                                                        "char": 59
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 119,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 119,
                                            "char": 60
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "serverList",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 120,
                                                    "char": 43
                                                },
                                                "name": "getServerList",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 120,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 120,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 122,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 122,
                                            "char": 24
                                        },
                                        "name": "setOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "\\Memcached",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 122,
                                                        "char": 61
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "OPT_PREFIX_KEY",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 122,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 122,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 122,
                                                "char": 61
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 122,
                                                        "char": 68
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "prefix",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 122,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 122,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 122,
                                                "char": 75
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 122,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 124,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "less",
                                        "left": {
                                            "type": "fcall",
                                            "name": "count",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "serverList",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 124,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 124,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 124,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 124,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 124,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "servers",
                                                    "expr": {
                                                        "type": "scall",
                                                        "dynamic-class": 0,
                                                        "class": "Arr",
                                                        "dynamic": 0,
                                                        "name": "get",
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "options",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 125,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 125,
                                                                "char": 48
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "servers",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 125,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 125,
                                                                "char": 57
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "empty-array",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 125,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 125,
                                                                "char": 61
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 125,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 125,
                                                    "char": 62
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "client",
                                                    "expr": {
                                                        "type": "scall",
                                                        "dynamic-class": 0,
                                                        "class": "Arr",
                                                        "dynamic": 0,
                                                        "name": "get",
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "options",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 126,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 126,
                                                                "char": 48
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "client",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 126,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 126,
                                                                "char": 56
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "empty-array",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 126,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 126,
                                                                "char": 60
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 126,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 126,
                                                    "char": 61
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "saslUser",
                                                    "expr": {
                                                        "type": "scall",
                                                        "dynamic-class": 0,
                                                        "class": "Arr",
                                                        "dynamic": 0,
                                                        "name": "get",
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "sasl",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 127,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 127,
                                                                "char": 45
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "user",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 127,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 127,
                                                                "char": 51
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 127,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 127,
                                                                "char": 53
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 127,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 127,
                                                    "char": 54
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "saslPass",
                                                    "expr": {
                                                        "type": "scall",
                                                        "dynamic-class": 0,
                                                        "class": "Arr",
                                                        "dynamic": 0,
                                                        "name": "get",
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "sasl",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 128,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 128,
                                                                "char": 45
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "pass",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 128,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 128,
                                                                "char": 51
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 128,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 128,
                                                                "char": 53
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 128,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 128,
                                                    "char": 54
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "failover",
                                                    "expr": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "static-constant-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "\\Memcached",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 130,
                                                                        "char": 63
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "OPT_CONNECT_TIMEOUT",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 130,
                                                                        "char": 63
                                                                    },
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 130,
                                                                    "char": 63
                                                                },
                                                                "value": {
                                                                    "type": "int",
                                                                    "value": "10",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 130,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 130,
                                                                "char": 67
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "static-constant-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "\\Memcached",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 131,
                                                                        "char": 63
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "OPT_DISTRIBUTION",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 131,
                                                                        "char": 63
                                                                    },
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 131,
                                                                    "char": 63
                                                                },
                                                                "value": {
                                                                    "type": "static-constant-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "\\Memcached",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 131,
                                                                        "char": 100
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "DISTRIBUTION_CONSISTENT",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 131,
                                                                        "char": 100
                                                                    },
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 131,
                                                                    "char": 100
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 131,
                                                                "char": 100
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "static-constant-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "\\Memcached",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 132,
                                                                        "char": 63
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "OPT_SERVER_FAILURE_LIMIT",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 132,
                                                                        "char": 63
                                                                    },
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 132,
                                                                    "char": 63
                                                                },
                                                                "value": {
                                                                    "type": "int",
                                                                    "value": "2",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 132,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 132,
                                                                "char": 66
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "static-constant-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "\\Memcached",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 133,
                                                                        "char": 63
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "OPT_REMOVE_FAILED_SERVERS",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 133,
                                                                        "char": 63
                                                                    },
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 133,
                                                                    "char": 63
                                                                },
                                                                "value": {
                                                                    "type": "bool",
                                                                    "value": "true",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 133,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 133,
                                                                "char": 69
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "static-constant-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "\\Memcached",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 134,
                                                                        "char": 63
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "OPT_RETRY_TIMEOUT",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                        "line": 134,
                                                                        "char": 63
                                                                    },
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 134,
                                                                    "char": 63
                                                                },
                                                                "value": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 135,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 135,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 135,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 135,
                                                    "char": 22
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "client",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_merge",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "failover",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 136,
                                                                    "char": 52
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 136,
                                                                "char": 52
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "client",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 136,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 136,
                                                                "char": 60
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 136,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 136,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 138,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "connection",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 138,
                                                        "char": 32
                                                    },
                                                    "name": "setOptions",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "client",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 138,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                            "line": 138,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 138,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 138,
                                                "char": 52
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
                                                                    "value": "Cannot set Memcached client options",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 139,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 139,
                                                                "char": 76
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 139,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 140,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 142,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "connection",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 142,
                                                        "char": 32
                                                    },
                                                    "name": "addServers",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "servers",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 142,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                            "line": 142,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 142,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 142,
                                                "char": 53
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
                                                                    "value": "Cannot connect to the Memcached server(s)",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 143,
                                                                    "char": 82
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 143,
                                                                "char": 82
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 143,
                                                        "char": 83
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 144,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 146,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "empty",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "saslUser",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 146,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 146,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 146,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "connection",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                            "line": 147,
                                                            "char": 32
                                                        },
                                                        "name": "setSaslAuthData",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "saslUser",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 147,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 147,
                                                                "char": 57
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "saslPass",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                    "line": 147,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                                "line": 147,
                                                                "char": 67
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 147,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 148,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 149,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 151,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 151,
                                            "char": 18
                                        },
                                        "name": "setSerializer",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 151,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 151,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 151,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 153,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "adapter",
                                            "expr": {
                                                "type": "variable",
                                                "value": "connection",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 153,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 153,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 154,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 156,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 156,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "adapter",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 156,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 156,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 157,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the already connected adapter or connects to the Memcached\n     * server(s)\n     *\n     * @return Memcached\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 111,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                        "line": 111,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                    "line": 110,
                    "last-line": 164,
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
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "keys",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 167,
                                    "char": 14
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 169,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "keys",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 169,
                                                "char": 25
                                            },
                                            "name": "getAdapter",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 169,
                                            "char": 39
                                        },
                                        "name": "getAllKeys",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 169,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 169,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 171,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "ternary",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "variable",
                                        "value": "keys",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 171,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 171,
                                    "char": 22
                                },
                                "right": {
                                    "type": "empty-array",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 171,
                                    "char": 27
                                },
                                "extra": {
                                    "type": "variable",
                                    "value": "keys",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 171,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 171,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 172,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Stores data in the adapter\n     *\n     * @return array\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 166,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                        "line": 166,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                    "line": 165,
                    "last-line": 181,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 182,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 184,
                                    "char": 23
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 184,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 186,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "connection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 186,
                                            "char": 31
                                        },
                                        "name": "getAdapter",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 186,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 186,
                                    "char": 44
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 187,
                                            "char": 37
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 187,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 187,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 187,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 187,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 189,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "\\Memcached",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 189,
                                        "char": 43
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "RES_NOTFOUND",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 189,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 189,
                                    "char": 43
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "connection",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 189,
                                        "char": 56
                                    },
                                    "name": "getResultCode",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 189,
                                    "char": 72
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 189,
                                "char": 72
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 190,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if an element exists in the cache\n     *\n     * @param string $key\n     *\n     * @return bool\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 183,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                        "line": 183,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                    "line": 182,
                    "last-line": 200,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 201,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 201,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 201,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 203,
                                        "char": 21
                                    },
                                    "name": "getAdapter",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 203,
                                    "char": 35
                                },
                                "name": "increment",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 203,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 203,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 203,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 203,
                                        "char": 56
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 203,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 204,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Increments a stored number\n     *\n     * @param string $key\n     * @param int    $value\n     *\n     * @return bool|int\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 201,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 202,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                        "line": 202,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                    "line": 201,
                    "last-line": 215,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 216,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 216,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 216,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 216,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 218,
                                        "char": 21
                                    },
                                    "name": "getAdapter",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 218,
                                    "char": 35
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 219,
                                            "char": 16
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 219,
                                        "char": 16
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 220,
                                                "char": 18
                                            },
                                            "name": "getSerializedData",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 220,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 220,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 220,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 220,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 221,
                                                "char": 18
                                            },
                                            "name": "getTtl",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "ttl",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 221,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 221,
                                                    "char": 29
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 222,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 222,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 222,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 223,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Stores data in the adapter\n     *\n     * @param string $key\n     * @param mixed  $value\n     * @param null   $ttl\n     *\n     * @return bool\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 217,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                        "line": 217,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                    "line": 216,
                    "last-line": 230,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "setSerializer",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "connection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "\\Memcached",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 231,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 231,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "serializer",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 233,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 234,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "map",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 234,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 236,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "map",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "php",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 237,
                                                    "char": 22
                                                },
                                                "value": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "\\Memcached",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 237,
                                                        "char": 50
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "SERIALIZER_PHP",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 237,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 237,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 237,
                                                "char": 50
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "json",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 238,
                                                    "char": 22
                                                },
                                                "value": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "\\Memcached",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 238,
                                                        "char": 51
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "SERIALIZER_JSON",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 238,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 238,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 238,
                                                "char": 51
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "igbinary",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 239,
                                                    "char": 22
                                                },
                                                "value": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "\\Memcached",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 240,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "SERIALIZER_IGBINARY",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 240,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 240,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 240,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 240,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 240,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 242,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "serializer",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtolower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 242,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "defaultSerializer",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 242,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 242,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 242,
                                                "char": 60
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 242,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 242,
                                    "char": 61
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 244,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "map",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 244,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "serializer",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 244,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 244,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                "line": 244,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "defaultSerializer",
                                            "expr": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 245,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 245,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 246,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 246,
                                            "char": 24
                                        },
                                        "name": "setOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "\\Memcached",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 246,
                                                        "char": 61
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "OPT_SERIALIZER",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 246,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 246,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 246,
                                                "char": 61
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "map",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 246,
                                                        "char": 66
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "serializer",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                        "line": 246,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                    "line": 246,
                                                    "char": 78
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                                "line": 246,
                                                "char": 78
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 246,
                                        "char": 79
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 247,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                            "line": 248,
                                            "char": 18
                                        },
                                        "name": "initSerializer",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                        "line": 248,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                                    "line": 249,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                            "line": 250,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the serializer. If it is a supported one it is set, otherwise\n     * the custom one is set.\n     *\n     * @param Memcached $connection\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
                    "line": 231,
                    "last-line": 251,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
            "line": 24,
            "char": 5
        },
        "file": "\/app\/phalcon\/Storage\/Adapter\/Libmemcached.zep",
        "line": 24,
        "char": 5
    }
]