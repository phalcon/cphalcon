[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger\\Adapter",
        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Logger",
                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                "line": 14,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Exception",
                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                "line": 15,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Formatter\\FormatterInterface",
                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                "line": 16,
                "char": 48
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Item",
                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                "line": 17,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
        "line": 19,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractAdapter",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "AdapterInterface",
                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                "line": 20,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultFormatter",
                    "default": {
                        "type": "string",
                        "value": "Line",
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                        "line": 26,
                        "char": 38
                    },
                    "docblock": "**\n     * Name of the default formatter class\n     *\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 32,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "formatter",
                    "docblock": "**\n     * Formatter\n     *\n     * @var <FormatterInterface>\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 39,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "inTransaction",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                        "line": 40,
                        "char": 36
                    },
                    "docblock": "**\n     * Tells if there is an active transaction or not\n     *\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 46,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "queue",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                        "line": 47,
                        "char": 25
                    },
                    "docblock": "**\n     * Array with messages queued in the transaction\n     *\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 51,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__destruct",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 54,
                                    "char": 17
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "inTransaction",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 54,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 54,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                            "line": 55,
                                            "char": 18
                                        },
                                        "name": "commit",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 55,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 56,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 58,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 58,
                                    "char": 14
                                },
                                "name": "close",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 58,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 59,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Destructor cleanup\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 52,
                    "last-line": 63,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "add",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "item",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Item",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 64,
                                "char": 35
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 64,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "queue",
                                    "expr": {
                                        "type": "variable",
                                        "value": "item",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 66,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 66,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 68,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 68,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 69,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a message to the queue\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 65,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 65,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                        "line": 65,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 64,
                    "last-line": 73,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "begin",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "inTransaction",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 76,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 76,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 78,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 78,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 79,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Starts a transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 75,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 75,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                        "line": 75,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 74,
                    "last-line": 83,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "commit",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "inTransaction",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 86,
                                    "char": 26
                                },
                                {
                                    "variable": "item",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 86,
                                    "char": 32
                                },
                                {
                                    "variable": "queue",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 86,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 88,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "inTransaction",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                            "line": 88,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "inTransaction",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                            "line": 88,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 88,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 88,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "queue",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                            "line": 89,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "queue",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                            "line": 89,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 89,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 89,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 91,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "inTransaction",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 91,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 91,
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
                                                    "value": "There is no active transaction",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                                    "line": 92,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                                "line": 92,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 92,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 93,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 98,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "queue",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 98,
                                "char": 27
                            },
                            "value": "item",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                            "line": 99,
                                            "char": 18
                                        },
                                        "name": "process",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "item",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                                    "line": 99,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                                "line": 99,
                                                "char": 31
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 99,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 100,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 103,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "inTransaction",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 103,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 103,
                                    "char": 34
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "queue",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 104,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 104,
                                    "char": 29
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "inTransaction",
                                    "expr": {
                                        "type": "variable",
                                        "value": "inTransaction",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 105,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 105,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 107,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 107,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 108,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Commits the internal transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 85,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 85,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                        "line": 85,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 84,
                    "last-line": 110,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFormatter",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 112,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 114,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                            "line": 114,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "formatter",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                            "line": 114,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 114,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 114,
                                    "char": 37
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 114,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 114,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "className",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "Phalcon\\\\Logger\\\\Formatter\\\\",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                                    "line": 115,
                                                    "char": 58
                                                },
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                                        "line": 115,
                                                        "char": 65
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "defaultFormatter",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                                        "line": 115,
                                                        "char": 82
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                                    "line": 115,
                                                    "char": 82
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                                "line": 115,
                                                "char": 82
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                            "line": 115,
                                            "char": 82
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 117,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "formatter",
                                            "expr": {
                                                "type": "new",
                                                "class": "className",
                                                "dynamic": 1,
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                                "line": 117,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                            "line": 117,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 118,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 120,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 120,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "formatter",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 120,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 120,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 121,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "FormatterInterface",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 111,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 111,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                        "line": 111,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 110,
                    "last-line": 125,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "inTransaction",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 128,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "inTransaction",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 128,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 128,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 129,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the whether the logger is currently in an active transaction or not\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 127,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                        "line": 127,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 126,
                    "last-line": 133,
                    "char": 19
                },
                {
                    "visibility": [
                        "abstract",
                        "public"
                    ],
                    "type": "method",
                    "name": "process",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "item",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Item",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 134,
                                "char": 48
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 134,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n      * Processes the message in the adapter\n      *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                        "line": 134,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 134,
                    "last-line": 138,
                    "char": 28
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rollback",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "inTransaction",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 141,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 143,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "inTransaction",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                            "line": 143,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "inTransaction",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                            "line": 143,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 143,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 143,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 145,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "inTransaction",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 145,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 145,
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
                                                    "value": "There is no active transaction",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                                    "line": 146,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                                "line": 146,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 146,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 147,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 149,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "queue",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 149,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 149,
                                    "char": 37
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "inTransaction",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 150,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 150,
                                    "char": 40
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "inTransaction",
                                    "expr": {
                                        "type": "variable",
                                        "value": "inTransaction",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 151,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 151,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 153,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 153,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 154,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Rollbacks the internal transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 140,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 140,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                        "line": 140,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 139,
                    "last-line": 158,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setFormatter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "formatter",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "FormatterInterface",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 159,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 159,
                            "char": 64
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
                                    "property": "formatter",
                                    "expr": {
                                        "type": "variable",
                                        "value": "formatter",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                        "line": 161,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 161,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 163,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 163,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                            "line": 164,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the message formatter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                    "line": 160,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                                "line": 160,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                        "line": 160,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
                    "line": 159,
                    "last-line": 165,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
            "line": 19,
            "char": 14
        },
        "file": "\/app\/phalcon\/Logger\/Adapter\/AbstractAdapter.zep",
        "line": 19,
        "char": 14
    }
]