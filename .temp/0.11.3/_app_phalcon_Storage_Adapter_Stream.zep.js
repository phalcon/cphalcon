[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Adapter",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Str",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                "line": 14,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                "line": 15,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Exception",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                "line": 16,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\SerializerFactory",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                "line": 17,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                "line": 18,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Stream adapter\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
        "line": 23,
        "char": 5
    },
    {
        "type": "class",
        "name": "Stream",
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
                    "name": "cacheDir",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 28,
                        "char": 26
                    },
                    "docblock": "**\n    * @var string\n    *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 32,
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
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 33,
                        "char": 27
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 41,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 42,
                                "char": 59
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 42,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 42,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 42,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 42,
                            "char": 88
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "cacheDir",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 44,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 46,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cacheDir",
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
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 46,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 46,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "cacheDir",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 46,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 46,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 46,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 46,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 46,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 46,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 47,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "empty",
                                "left": {
                                    "type": "variable",
                                    "value": "cacheDir",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 47,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 47,
                                "char": 27
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
                                                    "value": "The 'cacheDir' must be specified in the options",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 48,
                                                    "char": 80
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 48,
                                                "char": 80
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 48,
                                        "char": 81
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 49,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 54,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "cacheDir",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Str",
                                        "dynamic": 0,
                                        "name": "dirSeparator",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cacheDir",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 54,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 54,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 54,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 54,
                                    "char": 57
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "prefix",
                                    "expr": {
                                        "type": "string",
                                        "value": "phstrm-",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 55,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 55,
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
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 56,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 56,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 58,
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
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 58,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 58,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 58,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 58,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 58,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 60,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 60,
                                    "char": 14
                                },
                                "name": "initSerializer",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 60,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 61,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Stream constructor.\n     *\n     * @param array $options\n     *\n     * @throws Exception\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 42,
                    "last-line": 65,
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
                                    "variable": "directory",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 68,
                                    "char": 22
                                },
                                {
                                    "variable": "iterator",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 68,
                                    "char": 32
                                },
                                {
                                    "variable": "file",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 68,
                                    "char": 38
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 68,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 70,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 70,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 70,
                                    "char": 29
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "directory",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Str",
                                        "dynamic": 0,
                                        "name": "dirSeparator",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 71,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "cacheDir",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 71,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 71,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 71,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 71,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 71,
                                    "char": 58
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "iterator",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 72,
                                            "char": 30
                                        },
                                        "name": "rglob",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "directory",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 72,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\/*",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 72,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 72,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 72,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 72,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 72,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 74,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "iterator",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 74,
                                "char": 30
                            },
                            "value": "file",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "fcall",
                                                "name": "is_dir",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 75,
                                                            "char": 28
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 75,
                                                        "char": 28
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 75,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 75,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "fcall",
                                                "name": "unlink",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 75,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 75,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 75,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 75,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 75,
                                        "char": 47
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
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 76,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 76,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 77,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 78,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 80,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 80,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 81,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 67,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 67,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 66,
                    "last-line": 91,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 92,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 92,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 92,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 94,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 96,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 96,
                                        "char": 18
                                    },
                                    "name": "has",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 96,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 96,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 96,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 96,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 97,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 98,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 100,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 100,
                                            "char": 25
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 100,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 100,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 100,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 100,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "sub",
                                        "left": {
                                            "type": "cast",
                                            "left": "int",
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 101,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 101,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 101,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 101,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 101,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 103,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 103,
                                    "char": 21
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 103,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 103,
                                        "char": 29
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 103,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 103,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 103,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 104,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Decrements a stored number\n     *\n     * @param string $key\n     * @param int    $value\n     *\n     * @return bool|int\n     * @throws \\Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 92,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 93,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 93,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 92,
                    "last-line": 112,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 113,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "filepath",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 115,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 117,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 117,
                                        "char": 18
                                    },
                                    "name": "has",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 117,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 117,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 117,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 117,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 118,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 119,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 121,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "filepath",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 121,
                                            "char": 29
                                        },
                                        "name": "getFilepath",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 121,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 121,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 121,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 121,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 123,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "unlink",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "filepath",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 123,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 123,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 123,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 124,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 114,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 114,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 113,
                    "last-line": 133,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 134,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 134,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 134,
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
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 136,
                                    "char": 20
                                },
                                {
                                    "variable": "payload",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 136,
                                    "char": 29
                                },
                                {
                                    "variable": "filepath",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 136,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 138,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "filepath",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 138,
                                            "char": 29
                                        },
                                        "name": "getFilepath",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 138,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 138,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 138,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 138,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 140,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "file_exists",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "filepath",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 140,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 140,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 140,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 140,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultValue",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 141,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 142,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 144,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "payload",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "file_get_contents",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "filepath",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 144,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 144,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 144,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 144,
                                    "char": 52
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "payload",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "json_decode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "payload",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 145,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 145,
                                                "char": 42
                                            },
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 145,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 145,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 145,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 145,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 147,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "fcall",
                                    "name": "json_last_error",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 147,
                                    "char": 32
                                },
                                "right": {
                                    "type": "constant",
                                    "value": "JSON_ERROR_NONE",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 147,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 147,
                                "char": 50
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultValue",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 148,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 149,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 151,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 151,
                                    "char": 17
                                },
                                "name": "isExpired",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "payload",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 151,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 151,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 151,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultValue",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 152,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 153,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 155,
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
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Arr",
                                        "dynamic": 0,
                                        "name": "get",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "payload",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 155,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 155,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "content",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 155,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 155,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 155,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 155,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 155,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 155,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 157,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 157,
                                    "char": 21
                                },
                                "name": "getUnserializedData",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "content",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 157,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 157,
                                        "char": 49
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "defaultValue",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 157,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 157,
                                        "char": 63
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 157,
                                "char": 64
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 158,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads data from the adapter\n     *\n     * @param string $key\n     * @param null   $defaultValue\n     *\n     * @return mixed|null\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 135,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 135,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 134,
                    "last-line": 163,
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
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 166,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "adapter",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 166,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 166,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 167,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the already connected adapter or connects to the Memcached\n     * server(s)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 165,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 165,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 164,
                    "last-line": 171,
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
                                    "variable": "directory",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 174,
                                    "char": 22
                                },
                                {
                                    "variable": "iterator",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 174,
                                    "char": 32
                                },
                                {
                                    "variable": "file",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 174,
                                    "char": 38
                                },
                                {
                                    "variable": "split",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 174,
                                    "char": 45
                                },
                                {
                                    "variable": "results",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 174,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 176,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "results",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 176,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 176,
                                    "char": 27
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "directory",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Str",
                                        "dynamic": 0,
                                        "name": "dirSeparator",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 177,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "cacheDir",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 177,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 177,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 177,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 177,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 177,
                                    "char": 58
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "iterator",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 178,
                                            "char": 30
                                        },
                                        "name": "rglob",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "directory",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 178,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\/*",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 178,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 178,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 178,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 178,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 178,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 180,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "iterator",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 180,
                                "char": 30
                            },
                            "value": "file",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fcall",
                                            "name": "is_dir",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "file",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 181,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 181,
                                                    "char": 28
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 181,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 181,
                                        "char": 30
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "split",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "explode",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\/",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                    "line": 182,
                                                                    "char": 42
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                "line": 182,
                                                                "char": 42
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "file",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                    "line": 182,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                "line": 182,
                                                                "char": 48
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 182,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 182,
                                                    "char": 49
                                                },
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "results",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                "line": 183,
                                                                "char": 38
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "prefix",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                "line": 183,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 183,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Arr",
                                                            "dynamic": 0,
                                                            "name": "last",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "split",
                                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                        "line": 183,
                                                                        "char": 63
                                                                    },
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                    "line": 183,
                                                                    "char": 63
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 183,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 183,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 183,
                                                    "char": 64
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 184,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 185,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 187,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "results",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 187,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 188,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Stores data in the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 173,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 173,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 172,
                    "last-line": 196,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 197,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "payload",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 199,
                                    "char": 20
                                },
                                {
                                    "variable": "filepath",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 199,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 201,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "filepath",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 201,
                                            "char": 29
                                        },
                                        "name": "getFilepath",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 201,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 201,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 201,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 201,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 203,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "file_exists",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "filepath",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 203,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 203,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 203,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 203,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 204,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 205,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 207,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "payload",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "file_get_contents",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "filepath",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 207,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 207,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 207,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 207,
                                    "char": 50
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "payload",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "json_decode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "payload",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 208,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 208,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 208,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 208,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 210,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 210,
                                        "char": 22
                                    },
                                    "name": "isExpired",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "payload",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 210,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 210,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 210,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 210,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 211,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if an element exists in the cache and is not expired\n     *\n     * @param string $key\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 198,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 198,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 197,
                    "last-line": 221,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 222,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 222,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 222,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 224,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 226,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 226,
                                        "char": 18
                                    },
                                    "name": "has",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 226,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 226,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 226,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 226,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 227,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 228,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 230,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 230,
                                            "char": 25
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 230,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 230,
                                                "char": 33
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 230,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 230,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "add",
                                        "left": {
                                            "type": "cast",
                                            "left": "int",
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 231,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 231,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 231,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 231,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 231,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 233,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 233,
                                    "char": 21
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 233,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 233,
                                        "char": 29
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 233,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 233,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 233,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 234,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Increments a stored number\n     *\n     * @param string $key\n     * @param int    $value\n     *\n     * @return bool|int\n     * @throws \\Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 222,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 223,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 223,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 222,
                    "last-line": 245,
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
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 246,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 246,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 246,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 246,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "directory",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 248,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 249,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "payload",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 249,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 251,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "payload",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "created",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 252,
                                                    "char": 25
                                                },
                                                "value": {
                                                    "type": "fcall",
                                                    "name": "time",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 252,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 252,
                                                "char": 33
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "ttl",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 253,
                                                    "char": 25
                                                },
                                                "value": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 253,
                                                        "char": 32
                                                    },
                                                    "name": "getTtl",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "ttl",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                "line": 253,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 253,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 253,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 253,
                                                "char": 44
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "content",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 254,
                                                    "char": 25
                                                },
                                                "value": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 254,
                                                        "char": 32
                                                    },
                                                    "name": "getSerializedData",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                "line": 254,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 254,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 255,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 255,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 255,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 255,
                                    "char": 14
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "payload",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "json_encode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "payload",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 256,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 256,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 256,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 256,
                                    "char": 45
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "directory",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 257,
                                            "char": 30
                                        },
                                        "name": "getDir",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 257,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 257,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 257,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 257,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 259,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "is_dir",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "directory",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 259,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 259,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 259,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 259,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "mkdir",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "directory",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 260,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 260,
                                                "char": 28
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0777",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 260,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 260,
                                                "char": 34
                                            },
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 260,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 260,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 260,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 261,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 263,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 263,
                                    "char": 24
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "file_put_contents",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "directory",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 263,
                                                    "char": 54
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 263,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 263,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 263,
                                            "char": 59
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "payload",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 263,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 263,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 263,
                                    "char": 69
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 263,
                                "char": 69
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 264,
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
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 247,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 247,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 246,
                    "last-line": 272,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "getDir",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 273,
                                "char": 43
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 273,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "dirPrefix",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 275,
                                    "char": 22
                                },
                                {
                                    "variable": "dirFromFile",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 275,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 277,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "dirPrefix",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 277,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "cacheDir",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 277,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 277,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 277,
                                                "char": 49
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "prefix",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 277,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 277,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 277,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 277,
                                    "char": 56
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "dirFromFile",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Str",
                                        "dynamic": 0,
                                        "name": "dirFromFile",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "str_replace",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                    "line": 279,
                                                                    "char": 34
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "prefix",
                                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                    "line": 279,
                                                                    "char": 41
                                                                },
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                "line": 279,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 279,
                                                            "char": 41
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                "line": 279,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 279,
                                                            "char": 43
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "key",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                "line": 279,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 279,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                "line": 279,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 279,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 280,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 280,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 280,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 280,
                                    "char": 14
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 282,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "scall",
                                    "dynamic-class": 0,
                                    "class": "Str",
                                    "dynamic": 0,
                                    "name": "dirSeparator",
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "dirPrefix",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 282,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 282,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 282,
                                    "char": 45
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "dirFromFile",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 282,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 282,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 283,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the folder based on the cacheDir and the prefix\n     *\n     * @param string $key\n     *\n     * @return string\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 274,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 274,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 273,
                    "last-line": 287,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "getFilepath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 288,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 290,
                                        "char": 21
                                    },
                                    "name": "getDir",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 290,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 290,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 290,
                                    "char": 34
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "str_replace",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 290,
                                                    "char": 53
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "prefix",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 290,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 290,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 290,
                                            "char": 60
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 290,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 290,
                                            "char": 62
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 290,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 290,
                                            "char": 67
                                        },
                                        {
                                            "parameter": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 290,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 290,
                                            "char": 70
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 290,
                                    "char": 71
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 290,
                                "char": 71
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 291,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the full path to the file\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 289,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 289,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 288,
                    "last-line": 299,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "isExpired",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "payload",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 300,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "created",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 302,
                                    "char": 20
                                },
                                {
                                    "variable": "ttl",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 302,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 304,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "created",
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
                                                    "value": "payload",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 304,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 304,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "created",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 304,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 304,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "time",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 304,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 304,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 304,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 304,
                                    "char": 57
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ttl",
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
                                                    "value": "payload",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 305,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 305,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "ttl",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 305,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 305,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "3600",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 305,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 305,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 305,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 305,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 307,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "less",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "add",
                                        "left": {
                                            "type": "variable",
                                            "value": "created",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 307,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "ttl",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 307,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 307,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 307,
                                    "char": 32
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "time",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 307,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 307,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 308,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns if the cache has expired for this item or not\n     *\n     * @param array $payload\n     *\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 301,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 301,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 300,
                    "last-line": 314,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "rglob",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "pattern",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 315,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "dir",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 317,
                                    "char": 16
                                },
                                {
                                    "variable": "dirName",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 317,
                                    "char": 25
                                },
                                {
                                    "variable": "files",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 317,
                                    "char": 32
                                },
                                {
                                    "variable": "flags",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 317,
                                    "char": 39
                                },
                                {
                                    "variable": "recurse",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 317,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 319,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "dirName",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "fcall",
                                            "name": "dirname",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "pattern",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 319,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 319,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 319,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "\/*",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 319,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 319,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 319,
                                    "char": 44
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "files",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "glob",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "pattern",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 320,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 320,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 320,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 320,
                                    "char": 36
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "flags",
                                    "expr": {
                                        "type": "bitwise_or",
                                        "left": {
                                            "type": "constant",
                                            "value": "GLOB_ONLYDIR",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 321,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "constant",
                                            "value": "GLOB_NOSORT",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 321,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 321,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 321,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 323,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "fcall",
                                "name": "glob",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "dirName",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 323,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 323,
                                        "char": 32
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "flags",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 323,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                        "line": 323,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 323,
                                "char": 41
                            },
                            "value": "dir",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "dir",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "dir",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 324,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\/",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 324,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 324,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "basename",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "pattern",
                                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                                "line": 324,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 324,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 324,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 324,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 324,
                                            "char": 54
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "recurse",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                    "line": 325,
                                                    "char": 32
                                                },
                                                "name": "rglob",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "dir",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 325,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 325,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 325,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 325,
                                            "char": 43
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "files",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "array_merge",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "files",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 326,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 326,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "recurse",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                            "line": 326,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                        "line": 326,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                                "line": 326,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                            "line": 326,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                    "line": 327,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 329,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "files",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 329,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                            "line": 330,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @param string $pattern\n     *\n     * @return array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                                "line": 316,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                        "line": 316,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
                    "line": 315,
                    "last-line": 331,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
            "line": 23,
            "char": 5
        },
        "file": "\/app\/phalcon\/Storage\/Adapter\/Stream.zep",
        "line": 23,
        "char": 5
    }
]