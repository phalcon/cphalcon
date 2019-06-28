[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Adapter",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "APCUIterator",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                "line": 13,
                "char": 17
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                "line": 14,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                "line": 15,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Exception",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                "line": 16,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\SerializerFactory",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                "line": 17,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                "line": 18,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Storage\\Adapter\\Apcu\n *\n * Apcu adapter\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
        "line": 25,
        "char": 5
    },
    {
        "type": "class",
        "name": "Apcu",
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
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                        "line": 30,
                        "char": 27
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                    "line": 34,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 35,
                                "char": 59
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 35,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 35,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 35,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 35,
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
                                        "value": "ph-apcu-",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 40,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 40,
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
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 41,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 41,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 43,
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
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 43,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 43,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 43,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 43,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 43,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
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
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 45,
                                    "char": 14
                                },
                                "name": "initSerializer",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 45,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 46,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                    "line": 35,
                    "last-line": 50,
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
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "item",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 53,
                                    "char": 17
                                },
                                {
                                    "variable": "pattern",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 53,
                                    "char": 26
                                },
                                {
                                    "variable": "apc",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 53,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 53,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 54,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 54,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 56,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pattern",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "\/^",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 56,
                                                "char": 26
                                            },
                                            "right": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 56,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "prefix",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 56,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 56,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 56,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "\/",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 56,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 56,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 56,
                                    "char": 44
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "apc",
                                    "expr": {
                                        "type": "new",
                                        "class": "APCUIterator",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "pattern",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 57,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 57,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 57,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 57,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 58,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 58,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 60,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "apc",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 60,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 60,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 60,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 60,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 61,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 62,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 64,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "fcall",
                                "name": "iterator",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "apc",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 64,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 64,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 64,
                                "char": 35
                            },
                            "value": "item",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fcall",
                                            "name": "apcu_delete",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "item",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                            "line": 65,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                            "line": 65,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                        "line": 65,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 65,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 65,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 65,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "result",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                        "line": 66,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 66,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 67,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 68,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 70,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 70,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 71,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 52,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                        "line": 52,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                    "line": 51,
                    "last-line": 80,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 81,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 81,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 81,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "apcu_dec",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 83,
                                                "char": 30
                                            },
                                            "name": "getPrefixedKey",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                        "line": 83,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 83,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 83,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 83,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 83,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 83,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 83,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 84,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 81,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 82,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                        "line": 82,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                    "line": 81,
                    "last-line": 92,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 93,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "apcu_delete",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 95,
                                                "char": 33
                                            },
                                            "name": "getPrefixedKey",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                        "line": 95,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 95,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 95,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 95,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 95,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 96,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 94,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                        "line": 94,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                    "line": 93,
                    "last-line": 105,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 106,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 106,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 106,
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
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 108,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 110,
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
                                        "type": "fcall",
                                        "name": "apcu_fetch",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                        "line": 110,
                                                        "char": 39
                                                    },
                                                    "name": "getPrefixedKey",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "key",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                                "line": 110,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                            "line": 110,
                                                            "char": 58
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 110,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 110,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 110,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 110,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 112,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 112,
                                    "char": 21
                                },
                                "name": "getUnserializedData",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "content",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 112,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 112,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "defaultValue",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 112,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 112,
                                        "char": 63
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 112,
                                "char": 64
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 113,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads data from the adapter\n     *\n     * @param string $key\n     * @param null   $defaultValue\n     *\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 107,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                        "line": 107,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                    "line": 106,
                    "last-line": 120,
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
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 123,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "adapter",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 123,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 123,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 124,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 122,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                        "line": 122,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                    "line": 121,
                    "last-line": 130,
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
                                    "variable": "item",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 133,
                                    "char": 17
                                },
                                {
                                    "variable": "pattern",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 133,
                                    "char": 26
                                },
                                {
                                    "variable": "apc",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 133,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 133,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 134,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "results",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 134,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 136,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pattern",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "\/^",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 136,
                                                "char": 26
                                            },
                                            "right": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 136,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "prefix",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 136,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 136,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 136,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "\/",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 136,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 136,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 136,
                                    "char": 44
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "apc",
                                    "expr": {
                                        "type": "new",
                                        "class": "APCUIterator",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "pattern",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 137,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 137,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 137,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 137,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "results",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 138,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 138,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 140,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "apc",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 140,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 140,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 140,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 140,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "results",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 141,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 142,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 144,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "fcall",
                                "name": "iterator",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "apc",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 144,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 144,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 144,
                                "char": 35
                            },
                            "value": "item",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "results",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "item",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 145,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 145,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 145,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 145,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                    "line": 146,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 148,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "results",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 148,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 149,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 132,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                        "line": 132,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                    "line": 131,
                    "last-line": 157,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 158,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "apcu_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 160,
                                                "char": 33
                                            },
                                            "name": "getPrefixedKey",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                        "line": 160,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 160,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 160,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 160,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 160,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 161,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 159,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                        "line": 159,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                    "line": 158,
                    "last-line": 170,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 171,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 171,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 171,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "apcu_inc",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 173,
                                                "char": 30
                                            },
                                            "name": "getPrefixedKey",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                        "line": 173,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 173,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 173,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 173,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 173,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 173,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 173,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 174,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 171,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 172,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                        "line": 172,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                    "line": 171,
                    "last-line": 185,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 186,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 186,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 186,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 186,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "apcu_store",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 189,
                                                "char": 18
                                            },
                                            "name": "getPrefixedKey",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                        "line": 189,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 189,
                                                    "char": 37
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 189,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 189,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 190,
                                                "char": 18
                                            },
                                            "name": "getSerializedData",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                        "line": 190,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 190,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 190,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 190,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                "line": 191,
                                                "char": 18
                                            },
                                            "name": "getTtl",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "ttl",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                        "line": 191,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                                    "line": 191,
                                                    "char": 29
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                            "line": 192,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                        "line": 192,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 192,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                            "line": 193,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Stores data in the adapter\n     *\n     * @param string $key\n     * @param mixed  $value\n     * @param null   $ttl\n     *\n     * @return bool\n     * @throws \\Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                                "line": 187,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                        "line": 187,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
                    "line": 186,
                    "last-line": 194,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
            "line": 25,
            "char": 5
        },
        "file": "\/app\/phalcon\/Storage\/Adapter\/Apcu.zep",
        "line": 25,
        "char": 5
    }
]