[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Adapter",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                "line": 14,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Exception",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                "line": 15,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\SerializerFactory",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                "line": 16,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                "line": 17,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
        "line": 23,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Storage\\Adapter\\Redis\n *\n * Redis adapter\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
        "line": 24,
        "char": 5
    },
    {
        "type": "class",
        "name": "Redis",
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
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                        "line": 29,
                        "char": 27
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                    "line": 33,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 34,
                                "char": 59
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 34,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 34,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 34,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 34,
                            "char": 88
                        }
                    ],
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
                                            "value": "host",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 39,
                                            "char": 25
                                        }
                                    ],
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
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 39,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 39,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "host",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 39,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 39,
                                                "char": 57
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "127.0.0.1",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 39,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 39,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 39,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 39,
                                    "char": 69
                                },
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "options",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "port",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 40,
                                            "char": 25
                                        }
                                    ],
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
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
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 40,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 40,
                                                    "char": 57
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "port",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 40,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 40,
                                                    "char": 63
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "int",
                                                        "value": "6379",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 40,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 40,
                                                    "char": 69
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 40,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 40,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 40,
                                    "char": 70
                                },
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "options",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "index",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 41,
                                            "char": 26
                                        }
                                    ],
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
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 41,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 41,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "index",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 41,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 41,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 41,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 41,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 41,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 41,
                                    "char": 62
                                },
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "options",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "persistent",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 42,
                                            "char": 31
                                        }
                                    ],
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
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 42,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 42,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "persistent",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 42,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 42,
                                                "char": 63
                                            },
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 42,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 42,
                                                "char": 70
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 42,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 42,
                                    "char": 71
                                },
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "options",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "auth",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 43,
                                            "char": 25
                                        }
                                    ],
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
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 43,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 43,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "auth",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 43,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 43,
                                                "char": 57
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 43,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 43,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 43,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 43,
                                    "char": 60
                                },
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "options",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "socket",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 44,
                                            "char": 27
                                        }
                                    ],
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
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 44,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 44,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "socket",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 44,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 44,
                                                "char": 59
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 44,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 44,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 44,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 44,
                                    "char": 62
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "prefix",
                                    "expr": {
                                        "type": "string",
                                        "value": "ph-reds-",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 45,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 45,
                                    "char": 45
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 46,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 46,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 48,
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
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 48,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 48,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 48,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 48,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 48,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 49,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                    "line": 34,
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
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 59,
                                        "char": 21
                                    },
                                    "name": "getAdapter",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 59,
                                    "char": 35
                                },
                                "name": "flushDB",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 59,
                                "char": 45
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 60,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 58,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                        "line": 58,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                    "line": 57,
                    "last-line": 70,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 71,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 71,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 71,
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
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 73,
                                        "char": 21
                                    },
                                    "name": "getAdapter",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 73,
                                    "char": 35
                                },
                                "name": "decrBy",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 73,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 73,
                                        "char": 46
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 73,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 73,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 73,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 74,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Decrements a stored number\n     *\n     * @param string $key\n     * @param int    $value\n     *\n     * @return bool|int\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 71,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 72,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                        "line": 72,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                    "line": 71,
                    "last-line": 83,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 84,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "cast",
                                "left": "bool",
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 86,
                                            "char": 28
                                        },
                                        "name": "getAdapter",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 86,
                                        "char": 42
                                    },
                                    "name": "delete",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 86,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 86,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 86,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 86,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 87,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 85,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                        "line": 85,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                    "line": 84,
                    "last-line": 97,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 98,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 98,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 98,
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
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 100,
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
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 101,
                                                    "char": 18
                                                },
                                                "name": "getAdapter",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 101,
                                                "char": 32
                                            },
                                            "name": "get",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 101,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 101,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 101,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 101,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "defaultValue",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 103,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 103,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 103,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 104,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 99,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                        "line": 99,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                    "line": 98,
                    "last-line": 112,
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
                                    "variable": "auth",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 115,
                                    "char": 17
                                },
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 115,
                                    "char": 29
                                },
                                {
                                    "variable": "host",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 115,
                                    "char": 35
                                },
                                {
                                    "variable": "index",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 115,
                                    "char": 42
                                },
                                {
                                    "variable": "method",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 115,
                                    "char": 50
                                },
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 115,
                                    "char": 59
                                },
                                {
                                    "variable": "persistent",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 116,
                                    "char": 23
                                },
                                {
                                    "variable": "port",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 116,
                                    "char": 29
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 116,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 118,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 118,
                                    "char": 19
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 118,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 118,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 118,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 118,
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
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 119,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 119,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 119,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 119,
                                            "char": 43
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "connection",
                                            "expr": {
                                                "type": "new",
                                                "class": "\\Redis",
                                                "dynamic": 0,
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 120,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 120,
                                            "char": 42
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "auth",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 121,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "auth",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 121,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 121,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 121,
                                            "char": 43
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "host",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 122,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "host",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 122,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 122,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 122,
                                            "char": 43
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "index",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 123,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "index",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 123,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 123,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 123,
                                            "char": 44
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "persistent",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 124,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "persistent",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 124,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 124,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 124,
                                            "char": 49
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "port",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 125,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "port",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 125,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 125,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 125,
                                            "char": 43
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "method",
                                            "expr": {
                                                "type": "ternary",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "persistent",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 126,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "pconnect",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 126,
                                                    "char": 52
                                                },
                                                "extra": {
                                                    "type": "string",
                                                    "value": "connect",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 126,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 126,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 126,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 128,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "result",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 128,
                                                    "char": 37
                                                },
                                                "name": "method",
                                                "call-type": 2,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "host",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                            "line": 128,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 128,
                                                        "char": 51
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "port",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                            "line": 128,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 128,
                                                        "char": 57
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                                "line": 128,
                                                                "char": 64
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "lifetime",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                                "line": 128,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                            "line": 128,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 128,
                                                        "char": 73
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 128,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 128,
                                            "char": 74
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 130,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "result",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 130,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 130,
                                        "char": 24
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
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "string",
                                                                            "value": "Could not connect to the Redisd server [",
                                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                                            "line": 132,
                                                                            "char": 62
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "host",
                                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                                            "line": 132,
                                                                            "char": 69
                                                                        },
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                                        "line": 132,
                                                                        "char": 69
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": ":",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                                        "line": 132,
                                                                        "char": 73
                                                                    },
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                                    "line": 132,
                                                                    "char": 73
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "port",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                                    "line": 132,
                                                                    "char": 80
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                                "line": 132,
                                                                "char": 80
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "]",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                                "line": 133,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                            "line": 133,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 133,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 133,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 134,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 136,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "auth",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 136,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 136,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 136,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 136,
                                                    "char": 43
                                                },
                                                "name": "auth",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "auth",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                            "line": 136,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 136,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 136,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 136,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 136,
                                        "char": 55
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
                                                            "value": "Failed to authenticate with the Redis server",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                            "line": 137,
                                                            "char": 81
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 137,
                                                        "char": 81
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 137,
                                                "char": 82
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 138,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 140,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "greater",
                                            "left": {
                                                "type": "variable",
                                                "value": "index",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 140,
                                                "char": 22
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 140,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 140,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 140,
                                                    "char": 41
                                                },
                                                "name": "select",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "index",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                            "line": 140,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 140,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 140,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 140,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 140,
                                        "char": 56
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
                                                            "value": "Redis server selected database failed",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                            "line": 141,
                                                            "char": 74
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 141,
                                                        "char": 74
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 141,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 142,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 144,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 144,
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
                                                        "value": "\\Redis",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 144,
                                                        "char": 53
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "OPT_PREFIX",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 144,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 144,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 144,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 144,
                                                        "char": 60
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "prefix",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 144,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 144,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 144,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 144,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 146,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 146,
                                            "char": 18
                                        },
                                        "name": "setSerializer",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 146,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 146,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 146,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 147,
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
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 147,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 147,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 148,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 150,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 150,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "adapter",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 150,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 150,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 151,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the already connected adapter or connects to the Memcached\n     * server(s)\n     *\n     * @return mixed|\\Redis\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 114,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                        "line": 114,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                    "line": 113,
                    "last-line": 158,
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
                                "type": "mcall",
                                "variable": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 161,
                                        "char": 21
                                    },
                                    "name": "getAdapter",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 161,
                                    "char": 35
                                },
                                "name": "getKeys",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "*",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 161,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 161,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 161,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 162,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 160,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                        "line": 160,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                    "line": 159,
                    "last-line": 171,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 172,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "cast",
                                "left": "bool",
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 174,
                                            "char": 28
                                        },
                                        "name": "getAdapter",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 174,
                                        "char": 42
                                    },
                                    "name": "exists",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 174,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 174,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 174,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 174,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 175,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 173,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                        "line": 173,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                    "line": 172,
                    "last-line": 185,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 186,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 186,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 186,
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
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 188,
                                        "char": 21
                                    },
                                    "name": "getAdapter",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 188,
                                    "char": 35
                                },
                                "name": "incrBy",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 188,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 188,
                                        "char": 46
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 188,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 188,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 188,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 189,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 186,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 187,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                        "line": 187,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                    "line": 186,
                    "last-line": 200,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 201,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 201,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 201,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 201,
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
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 203,
                                        "char": 21
                                    },
                                    "name": "getAdapter",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 203,
                                    "char": 35
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 204,
                                            "char": 16
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 204,
                                        "char": 16
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 205,
                                                "char": 18
                                            },
                                            "name": "getSerializedData",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 205,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 205,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 205,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 205,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 206,
                                                "char": 18
                                            },
                                            "name": "getTtl",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "ttl",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 206,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 206,
                                                    "char": 29
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 207,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 207,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 207,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 208,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 202,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                        "line": 202,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                    "line": 201,
                    "last-line": 215,
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
                                "value": "\\Redis",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 216,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 216,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "serializer",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 218,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 219,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "map",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 219,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 221,
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
                                                    "value": "none",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 222,
                                                    "char": 18
                                                },
                                                "value": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "\\Redis",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 222,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "SERIALIZER_NONE",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 222,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 222,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 222,
                                                "char": 43
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "php",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 223,
                                                    "char": 18
                                                },
                                                "value": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "\\Redis",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 224,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "SERIALIZER_PHP",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 224,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 224,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 224,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 224,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 224,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 230,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "defined",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "\\\\Redis::SERIALIZER_IGBINARY",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 230,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 230,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 230,
                                "char": 50
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "map",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "igbinary",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 231,
                                                    "char": 29
                                                }
                                            ],
                                            "expr": {
                                                "type": "fcall",
                                                "name": "constant",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "\\\\Redis::SERIALIZER_IGBINARY",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                            "line": 231,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 231,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 231,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 231,
                                            "char": 71
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 232,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 234,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "defined",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "\\\\Redis::SERIALIZER_MSGPACK",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 234,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 234,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 234,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "map",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "msgpack",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 235,
                                                    "char": 28
                                                }
                                            ],
                                            "expr": {
                                                "type": "fcall",
                                                "name": "constant",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "\\\\Redis::SERIALIZER_MSGPACK",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                            "line": 235,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 235,
                                                        "char": 69
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 235,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 235,
                                            "char": 70
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 236,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 238,
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
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 238,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "defaultSerializer",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 238,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 238,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 238,
                                                "char": 60
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 238,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 238,
                                    "char": 61
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 240,
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
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 240,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "serializer",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 240,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 240,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                "line": 240,
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
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 241,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 241,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 242,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 242,
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
                                                        "value": "\\Redis",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 242,
                                                        "char": 57
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "OPT_SERIALIZER",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 242,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 242,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 242,
                                                "char": 57
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "map",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 242,
                                                        "char": 62
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "serializer",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                        "line": 242,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                    "line": 242,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                                "line": 242,
                                                "char": 74
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 242,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 243,
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
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                            "line": 244,
                                            "char": 18
                                        },
                                        "name": "initSerializer",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                        "line": 244,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                                    "line": 245,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                            "line": 246,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the serializer. If it is a supported one it is set, otherwise\n     * the custom one is set.\n     *\n     * @param \\Redis $connection\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
                    "line": 216,
                    "last-line": 247,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
            "line": 24,
            "char": 5
        },
        "file": "\/app\/phalcon\/Storage\/Adapter\/Redis.zep",
        "line": 24,
        "char": 5
    }
]