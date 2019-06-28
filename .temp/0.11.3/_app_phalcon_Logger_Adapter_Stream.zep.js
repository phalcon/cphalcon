[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger\\Adapter",
        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Adapter",
                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                "line": 13,
                "char": 27
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Exception",
                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                "line": 14,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Formatter\\FormatterInterface",
                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                "line": 15,
                "char": 48
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Item",
                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                "line": 16,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "UnexpectedValueException",
                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                "line": 17,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
        "line": 33,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Logger\\Adapter\\Stream\n *\n * Adapter to store logs in plain text files\n *\n *```php\n * $logger = new \\Phalcon\\Logger\\Adapter\\Stream(\"app\/logs\/test.log\");\n *\n * $logger->log(\"This is a message\");\n * $logger->log(\\Phalcon\\Logger::ERROR, \"This is an error\");\n * $logger->error(\"This is another error\");\n *\n * $logger->close();\n *```\n *",
        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
        "line": 34,
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
                    "name": "handler",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                        "line": 41,
                        "char": 29
                    },
                    "docblock": "**\n     * Stream handler resource\n     *\n     * @var resource|null\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                    "line": 47,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "mode",
                    "default": {
                        "type": "string",
                        "value": "ab",
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                        "line": 48,
                        "char": 24
                    },
                    "docblock": "**\n     * The file open mode. Defaults to \"ab\"\n     *\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                    "line": 54,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "name",
                    "docblock": "**\n     * Stream name\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 55,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                    "line": 61,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "options",
                    "docblock": "**\n     * Path options\n     *\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                    "line": 66,
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 67,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                "line": 67,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 67,
                            "char": 65
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "mode",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 69,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 74,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "mode",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 74,
                                    "char": 38
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 74,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "mode",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 74,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 74,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                "line": 74,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "memstr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "mode",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                    "line": 75,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 75,
                                                "char": 27
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "r",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                    "line": 75,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 75,
                                                "char": 30
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 75,
                                        "char": 32
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
                                                            "value": "Adapter cannot be opened in read mode",
                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                            "line": 76,
                                                            "char": 74
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                        "line": 76,
                                                        "char": 74
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 76,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 77,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 78,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 80,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "mode",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 80,
                                    "char": 19
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 80,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                "line": 80,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "mode",
                                            "expr": {
                                                "type": "string",
                                                "value": "ab",
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 81,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 81,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 82,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 84,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "name",
                                    "expr": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 84,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 84,
                                    "char": 30
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "mode",
                                    "expr": {
                                        "type": "variable",
                                        "value": "mode",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 85,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 85,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 86,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor. Accepts the name and some options\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                    "line": 67,
                    "last-line": 90,
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
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "result",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 93,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 93,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 95,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "is_resource",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 95,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "handler",
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 95,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 95,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 95,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                "line": 95,
                                "char": 39
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
                                                "type": "fcall",
                                                "name": "fclose",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                "line": 96,
                                                                "char": 38
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "handler",
                                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                "line": 96,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                            "line": 96,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                        "line": 96,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 96,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 96,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 97,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 99,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "handler",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 99,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 99,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 101,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                "line": 101,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 102,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Closes the stream\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                "line": 92,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                        "line": 92,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                    "line": 91,
                    "last-line": 106,
                    "char": 19
                },
                {
                    "visibility": [
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
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                "line": 107,
                                "char": 39
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 107,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "formatter",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 109,
                                    "char": 22
                                },
                                {
                                    "variable": "formattedMessage",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 109,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 111,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "is_resource",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                    "line": 111,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "handler",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                    "line": 111,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 111,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 111,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 111,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                "line": 111,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "handler",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "fopen",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                "line": 112,
                                                                "char": 44
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "name",
                                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                "line": 112,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                            "line": 112,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                        "line": 112,
                                                        "char": 49
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                "line": 112,
                                                                "char": 56
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "mode",
                                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                "line": 112,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                            "line": 112,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                        "line": 112,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 112,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 112,
                                            "char": 62
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 114,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fcall",
                                            "name": "is_resource",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                            "line": 114,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "handler",
                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                            "line": 114,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                        "line": 114,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                    "line": 114,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 114,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 114,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "handler",
                                                    "expr": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                        "line": 115,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                    "line": 115,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 117,
                                            "char": 21
                                        },
                                        {
                                            "type": "throw",
                                            "expr": {
                                                "type": "new",
                                                "class": "UnexpectedValueException",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "sprintf",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "The file '%s' cannot be opened with mode '%s'",
                                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                        "line": 119,
                                                                        "char": 70
                                                                    },
                                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                    "line": 119,
                                                                    "char": 70
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                            "line": 120,
                                                                            "char": 30
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "name",
                                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                            "line": 120,
                                                                            "char": 35
                                                                        },
                                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                        "line": 120,
                                                                        "char": 35
                                                                    },
                                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                    "line": 120,
                                                                    "char": 35
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                            "line": 121,
                                                                            "char": 30
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "mode",
                                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                            "line": 122,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                        "line": 122,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                                    "line": 122,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                            "line": 123,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                        "line": 123,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 123,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 124,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 125,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 127,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "formatter",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 127,
                                            "char": 37
                                        },
                                        "name": "getFormatter",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 127,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 127,
                                    "char": 52
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "formattedMessage",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "formatter",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 128,
                                            "char": 42
                                        },
                                        "name": "format",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "item",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                    "line": 128,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 128,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 128,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                    "line": 128,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 130,
                            "char": 14
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "fwrite",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 130,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "handler",
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                                "line": 130,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 130,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 130,
                                        "char": 29
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "formattedMessage",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                            "line": 130,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                        "line": 130,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                                "line": 130,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                            "line": 131,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Processes the message i.e. writes it to the file\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                        "line": 108,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
                    "line": 107,
                    "last-line": 132,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
            "line": 34,
            "char": 5
        },
        "file": "\/app\/phalcon\/Logger\/Adapter\/Stream.zep",
        "line": 34,
        "char": 5
    }
]