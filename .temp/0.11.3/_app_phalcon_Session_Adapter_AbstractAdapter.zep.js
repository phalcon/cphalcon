[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Session\\Adapter",
        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                "line": 13,
                "char": 45
            }
        ],
        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "SessionHandlerInterface",
                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                "line": 14,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
        "line": 16,
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
                "value": "SessionHandlerInterface",
                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                "line": 17,
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
                    "name": "adapter",
                    "docblock": "**\n     * @var <AdapterInterface>\n     *",
                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                    "line": 25,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "close",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 28,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 29,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Close\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 27,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                        "line": 27,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                    "line": 26,
                    "last-line": 33,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "destroy",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "id",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 34,
                            "char": 35
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "empty",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                                "line": 36,
                                                "char": 21
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                            "line": 36,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                        "line": 36,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                    "line": 36,
                                    "char": 24
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                            "line": 36,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "adapter",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                            "line": 36,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                        "line": 36,
                                        "char": 40
                                    },
                                    "name": "has",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                                "line": 36,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                            "line": 36,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                    "line": 36,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 36,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                                "line": 37,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "adapter",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                                "line": 37,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                            "line": 37,
                                            "char": 34
                                        },
                                        "name": "delete",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "id",
                                                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                                    "line": 37,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                                "line": 37,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                        "line": 37,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                    "line": 38,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 40,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 40,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 41,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Destroy\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 35,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                        "line": 35,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                    "line": 34,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "gc",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "maxlifetime",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 46,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 48,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 49,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Garbage Collector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 47,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                        "line": 47,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                    "line": 46,
                    "last-line": 53,
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
                            "name": "id",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 54,
                            "char": 32
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                        "line": 56,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                        "line": 56,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                    "line": 56,
                                    "char": 30
                                },
                                "name": "get",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "id",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                            "line": 56,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                        "line": 56,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 56,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 57,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Read\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 55,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                        "line": 55,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                    "line": 54,
                    "last-line": 61,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "open",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "savePath",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 62,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "sessionName",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 62,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 64,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 65,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Open\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 63,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                        "line": 63,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                    "line": 62,
                    "last-line": 69,
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
                            "name": "id",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 70,
                            "char": 33
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 70,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                        "line": 72,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "adapter",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                        "line": 72,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                    "line": 72,
                                    "char": 30
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "id",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                            "line": 72,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                        "line": 72,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                            "line": 72,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                        "line": 72,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 72,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                            "line": 73,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Write\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                                "line": 71,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                        "line": 71,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
                    "line": 70,
                    "last-line": 74,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
            "line": 16,
            "char": 14
        },
        "file": "\/app\/phalcon\/Session\/Adapter\/AbstractAdapter.zep",
        "line": 16,
        "char": 14
    }
]