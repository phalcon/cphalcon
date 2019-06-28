[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Session\\Adapter",
        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "SessionHandlerInterface",
                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                "line": 13,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
        "line": 30,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Session\\Adapter\\Noop\n *\n * This is an \"empty\" or null adapter. It can be used for testing or any\n * other purpose that no session needs to be invoked\n *\n * ```php\n * <?php\n *\n * use Phalcon\\Session\\Manager;\n * use Phalcon\\Session\\Adapter\\Noop;\n *\n * $session = new Manager();\n * $session->setHandler(new Noop());\n * ```\n *",
        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
        "line": 31,
        "char": 5
    },
    {
        "type": "class",
        "name": "Noop",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "SessionHandlerInterface",
                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                "line": 32,
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
                    "name": "connection",
                    "docblock": "**\n     * The connection of some adapters\n     *",
                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                    "line": 42,
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
                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                        "line": 43,
                        "char": 27
                    },
                    "docblock": "**\n     * Session options\n     *\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                    "line": 49,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "prefix",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                        "line": 50,
                        "char": 24
                    },
                    "docblock": "**\n     * Session prefix\n     *\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                    "line": 56,
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
                        "value": "8600",
                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                        "line": 57,
                        "char": 25
                    },
                    "docblock": "**\n     * Time To Live\n     *\n     * @var int\n     *",
                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                    "line": 61,
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
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 62,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 62,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "prefix",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                    "line": 64,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 66,
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
                                        "value": "prefix",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                        "line": 66,
                                        "char": 43
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                            "line": 66,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "prefix",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                            "line": 66,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                        "line": 66,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                    "line": 66,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 66,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "prefix",
                                            "expr": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                                "line": 67,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                            "line": 67,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                    "line": 68,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 70,
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
                                        "type": "variable",
                                        "value": "prefix",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                        "line": 70,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                    "line": 70,
                                    "char": 35
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                        "line": 71,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                    "line": 71,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 72,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                        "line": 63,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                    "line": 62,
                    "last-line": 76,
                    "char": 19
                },
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
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 79,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 80,
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
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 78,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                        "line": 78,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                    "line": 77,
                    "last-line": 84,
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
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 85,
                            "char": 35
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 87,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 88,
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
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 86,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                        "line": 86,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                    "line": 85,
                    "last-line": 92,
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
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 93,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 95,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 96,
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
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 94,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                        "line": 94,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                    "line": 93,
                    "last-line": 100,
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
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 101,
                            "char": 32
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 103,
                                "char": 16
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 104,
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
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 102,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                        "line": 102,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                    "line": 101,
                    "last-line": 108,
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
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 109,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "sessionName",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 109,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 111,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 112,
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
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 110,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                        "line": 110,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                    "line": 109,
                    "last-line": 116,
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
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 117,
                            "char": 33
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 117,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 119,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 120,
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
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 118,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                        "line": 118,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                    "line": 117,
                    "last-line": 124,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getPrefixedName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 125,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "cast",
                                        "left": "string",
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                            "line": 127,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                        "line": 127,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                    "line": 127,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 129,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                        "line": 129,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "prefix",
                                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                        "line": 129,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                    "line": 129,
                                    "char": 29
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                    "line": 129,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 129,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                            "line": 130,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Helper method to get the name prefixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                                "line": 126,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                        "line": 126,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
                    "line": 125,
                    "last-line": 131,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
            "line": 31,
            "char": 5
        },
        "file": "\/app\/phalcon\/Session\/Adapter\/Noop.zep",
        "line": 31,
        "char": 5
    }
]