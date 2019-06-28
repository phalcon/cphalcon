[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Annotations\\Adapter",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                "line": 13,
                "char": 48
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Reflection",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                "line": 14,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Stores the parsed annotations in APCu. This adapter is suitable for production\n *\n *```php\n * use Phalcon\\Annotations\\Adapter\\Apcu;\n *\n * $annotations = new Apcu();\n *```\n *",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
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
                    "name": "prefix",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                        "line": 30,
                        "char": 24
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                    "line": 34,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "ttl",
                    "default": {
                        "type": "int",
                        "value": "172800",
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                        "line": 35,
                        "char": 27
                    },
                    "docblock": "**\n     * @var int\n     *",
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
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
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                "line": 40,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                            "line": 40,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "prefix",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                    "line": 42,
                                    "char": 19
                                },
                                {
                                    "variable": "ttl",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                    "line": 42,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                            "line": 44,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "prefix",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                    "line": 44,
                                    "char": 42
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                        "line": 44,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "prefix",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                        "line": 44,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                    "line": 44,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                "line": 44,
                                "char": 42
                            },
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
                                                "type": "variable",
                                                "value": "prefix",
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                "line": 45,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                            "line": 45,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                    "line": 46,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                            "line": 48,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "ttl",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                    "line": 48,
                                    "char": 41
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                        "line": 48,
                                        "char": 30
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "lifetime",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                        "line": 48,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                    "line": 48,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                "line": 48,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "ttl",
                                            "expr": {
                                                "type": "variable",
                                                "value": "ttl",
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                "line": 49,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                            "line": 49,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                    "line": 50,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                            "line": 51,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Annotations\\Adapter\\Apcu constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                        "line": 41,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                    "line": 40,
                    "last-line": 55,
                    "char": 19
                },
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
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                            "line": 56,
                            "char": 37
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "apcu_fetch",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "strtolower",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "_PHAN",
                                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                                "line": 60,
                                                                "char": 23
                                                            },
                                                            "right": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                                    "line": 60,
                                                                    "char": 30
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "prefix",
                                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                                    "line": 60,
                                                                    "char": 38
                                                                },
                                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                                "line": 60,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                            "line": 60,
                                                            "char": 38
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                            "line": 61,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                        "line": 61,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                    "line": 61,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                            "line": 62,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                        "line": 62,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                "line": 62,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                            "line": 63,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads parsed annotations from APCu\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Reflection",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                    "line": 56,
                                    "char": 55
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                "line": 56,
                                "char": 55
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                "line": 57,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                        "line": 57,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                    "line": 56,
                    "last-line": 67,
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
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                            "line": 68,
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
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                "line": 68,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                            "line": 68,
                            "char": 57
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
                                            "type": "fcall",
                                            "name": "strtolower",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "_PHAN",
                                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                                "line": 72,
                                                                "char": 23
                                                            },
                                                            "right": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                                    "line": 72,
                                                                    "char": 30
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "prefix",
                                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                                    "line": 72,
                                                                    "char": 38
                                                                },
                                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                                "line": 72,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                            "line": 72,
                                                            "char": 38
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                            "line": 73,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                        "line": 73,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                    "line": 73,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                            "line": 73,
                                            "char": 14
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                        "line": 73,
                                        "char": 14
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                            "line": 74,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                        "line": 74,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                "line": 75,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "ttl",
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                                "line": 76,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                            "line": 76,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                        "line": 76,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                "line": 76,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                            "line": 77,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Writes parsed annotations to APCu\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                                "line": 69,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                        "line": 69,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
                    "line": 68,
                    "last-line": 78,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
            "line": 25,
            "char": 5
        },
        "file": "\/app\/phalcon\/Annotations\/Adapter\/Apcu.zep",
        "line": 25,
        "char": 5
    }
]