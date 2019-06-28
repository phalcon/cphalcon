[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Cache",
        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                "line": 13,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Exception\\Exception",
                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                "line": 14,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\AbstractFactory",
                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                "line": 15,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\SerializerFactory",
                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                "line": 16,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Factory to create Cache adapters\n *",
        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
        "line": 21,
        "char": 5
    },
    {
        "type": "class",
        "name": "AdapterFactory",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractFactory",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "serializerFactory",
                    "docblock": "**\n     * @var SerializerFactory\n     *",
                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                    "line": 30,
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
                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                "line": 31,
                                "char": 59
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                "line": 31,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                            "line": 31,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "services",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                "line": 31,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                            "line": 31,
                            "char": 89
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
                                    "property": "serializerFactory",
                                    "expr": {
                                        "type": "variable",
                                        "value": "factory",
                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                        "line": 33,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                    "line": 33,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                            "line": 35,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                    "line": 35,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 35,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                        "line": 35,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                "line": 35,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                            "line": 36,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * AdapterFactory constructor.\n     *",
                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                    "line": 31,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "newInstance",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                            "line": 41,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                "line": 41,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                            "line": 41,
                            "char": 66
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                    "line": 43,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                            "line": 45,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                    "line": 45,
                                    "char": 14
                                },
                                "name": "checkService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 45,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                        "line": 45,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                "line": 45,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                            "line": 47,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                "line": 47,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "services",
                                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                "line": 47,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 47,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 47,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                        "line": 47,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                    "line": 47,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                "line": 47,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "definition",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                        "line": 48,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mapper",
                                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                        "line": 48,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                    "line": 48,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                    "line": 48,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                "line": 48,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 48,
                                            "char": 58
                                        },
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "services",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                    "line": 49,
                                                    "char": 36
                                                }
                                            ],
                                            "expr": {
                                                "type": "new",
                                                "class": "definition",
                                                "dynamic": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                                "line": 49,
                                                                "char": 62
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "serializerFactory",
                                                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                                "line": 49,
                                                                "char": 80
                                                            },
                                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                            "line": 49,
                                                            "char": 80
                                                        },
                                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                        "line": 49,
                                                        "char": 80
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                            "line": 49,
                                                            "char": 89
                                                        },
                                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                        "line": 49,
                                                        "char": 89
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                                "line": 49,
                                                "char": 90
                                            },
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 49,
                                            "char": 90
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                    "line": 50,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                            "line": 52,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                        "line": 52,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                        "line": 52,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                    "line": 52,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                    "line": 52,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                "line": 52,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                            "line": 53,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create a new instance of the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AbstractAdapter",
                                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                    "line": 42,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                "line": 42,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                        "line": 42,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                    "line": 41,
                    "last-line": 57,
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
                                            "value": "apcu",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 61,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Cache\\\\Adapter\\\\Apcu",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 61,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                        "line": 61,
                                        "char": 59
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "libmemcached",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 62,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Cache\\\\Adapter\\\\Libmemcached",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 62,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                        "line": 62,
                                        "char": 67
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "memory",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 63,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Cache\\\\Adapter\\\\Memory",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 63,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                        "line": 63,
                                        "char": 61
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "redis",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 64,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Cache\\\\Adapter\\\\Redis",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 64,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                        "line": 64,
                                        "char": 60
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "stream",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 65,
                                            "char": 26
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Cache\\\\Adapter\\\\Stream",
                                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                            "line": 66,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                        "line": 66,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                "line": 66,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                            "line": 67,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the available adapters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                                "line": 59,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                        "line": 59,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
                    "line": 58,
                    "last-line": 68,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
            "line": 21,
            "char": 5
        },
        "file": "\/app\/phalcon\/Cache\/AdapterFactory.zep",
        "line": 21,
        "char": 5
    }
]