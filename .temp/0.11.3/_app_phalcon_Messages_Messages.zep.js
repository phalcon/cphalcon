[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Messages\/Messages.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Messages",
        "file": "\/app\/phalcon\/Messages\/Messages.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ArrayAccess",
                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                "line": 13,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Messages\/Messages.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Countable",
                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                "line": 14,
                "char": 14
            }
        ],
        "file": "\/app\/phalcon\/Messages\/Messages.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Iterator",
                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                "line": 15,
                "char": 13
            }
        ],
        "file": "\/app\/phalcon\/Messages\/Messages.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "JsonSerializable",
                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                "line": 16,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Messages\/Messages.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                "line": 17,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Messages\/Messages.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Exception",
                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                "line": 18,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Messages\/Messages.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\MessageInterface",
                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                "line": 19,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Messages\/Messages.zep",
        "line": 23,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Represents a collection of messages\n *",
        "file": "\/app\/phalcon\/Messages\/Messages.zep",
        "line": 24,
        "char": 5
    },
    {
        "type": "class",
        "name": "Messages",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ArrayAccess",
                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                "line": 24,
                "char": 38
            },
            {
                "type": "variable",
                "value": "Countable",
                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                "line": 24,
                "char": 49
            },
            {
                "type": "variable",
                "value": "Iterator",
                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                "line": 24,
                "char": 59
            },
            {
                "type": "variable",
                "value": "JsonSerializable",
                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                "line": 25,
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
                    "name": "position",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 29,
                        "char": 27
                    },
                    "docblock": "**\n     * @var int\n     *",
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 33,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "messages",
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 38,
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
                            "name": "messages",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 39,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 39,
                            "char": 52
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
                                    "property": "messages",
                                    "expr": {
                                        "type": "variable",
                                        "value": "messages",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 41,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 41,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 42,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Messages\\Messages constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 40,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 39,
                    "last-line": 52,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "appendMessage",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "MessageInterface",
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 53,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 53,
                            "char": 61
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
                                    "property": "messages",
                                    "expr": {
                                        "type": "variable",
                                        "value": "message",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 55,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 55,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 56,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Appends a message to the collection\n     *\n     *```php\n     * $messages->appendMessage(\n     *     new \\Phalcon\\Messages\\Message(\"This is a message\")\n     * );\n     *```\n     *",
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 53,
                    "last-line": 66,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "appendMessages",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "messages",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 67,
                            "char": 44
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "currentMessages",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 69,
                                    "char": 28
                                },
                                {
                                    "variable": "finalMessages",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 69,
                                    "char": 43
                                },
                                {
                                    "variable": "message",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 69,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 71,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 71,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 71,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 71,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 71,
                                    "char": 38
                                },
                                "right": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 71,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 71,
                                        "char": 57
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 71,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 71,
                                    "char": 66
                                },
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 71,
                                "char": 66
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
                                                    "value": "The messages must be array or object",
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 72,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 72,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 72,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 73,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 75,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "currentMessages",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 75,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 75,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 75,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 75,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 77,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "messages",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 77,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 77,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 77,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 77,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "currentMessages",
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 81,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 81,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 81,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 81,
                                        "char": 48
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "finalMessages",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_merge",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "currentMessages",
                                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                                    "line": 82,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                                "line": 82,
                                                                "char": 64
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "messages",
                                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                                    "line": 82,
                                                                    "char": 74
                                                                },
                                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                                "line": 82,
                                                                "char": 74
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 82,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 82,
                                                    "char": 75
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 83,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "finalMessages",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "messages",
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 84,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 84,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 85,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 87,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "messages",
                                            "expr": {
                                                "type": "variable",
                                                "value": "finalMessages",
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 87,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 87,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 88,
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
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 97,
                                            "char": 22
                                        },
                                        "name": "rewind",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 97,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 99,
                                    "char": 17
                                },
                                {
                                    "type": "while",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 99,
                                            "char": 28
                                        },
                                        "name": "valid",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 99,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "message",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "messages",
                                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                            "line": 100,
                                                            "char": 40
                                                        },
                                                        "name": "current",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 100,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 100,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 101,
                                            "char": 20
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 101,
                                                    "char": 22
                                                },
                                                "name": "appendMessage",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "message",
                                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                            "line": 101,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 101,
                                                        "char": 44
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 101,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 102,
                                            "char": 24
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "messages",
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 102,
                                                    "char": 26
                                                },
                                                "name": "next",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 102,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 103,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 104,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 105,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Appends an array of messages to the collection\n     *\n     *```php\n     * $messages->appendMessages($messagesArray);\n     *```\n     *\n     * @param \\Phalcon\\Messages\\MessageInterface[] messages\n     *",
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 67,
                    "last-line": 109,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "count",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "count",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 112,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "messages",
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 112,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 112,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 112,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 112,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 113,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the number of messages in the list\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 111,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 111,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 110,
                    "last-line": 117,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "current",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 120,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "messages",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 120,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 120,
                                    "char": 30
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 120,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "position",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 120,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 120,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 120,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 121,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current message in the iterator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 119,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 119,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 119,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 118,
                    "last-line": 125,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "filter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "fieldName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 126,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "filtered",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 128,
                                    "char": 21
                                },
                                {
                                    "variable": "messages",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 128,
                                    "char": 31
                                },
                                {
                                    "variable": "message",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 128,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 130,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "filtered",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 130,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 130,
                                    "char": 26
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "messages",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 131,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 131,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 131,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 131,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 133,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "messages",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 133,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 133,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 133,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 133,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "messages",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 138,
                                        "char": 37
                                    },
                                    "value": "message",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "method_exists",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "message",
                                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                            "line": 142,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 142,
                                                        "char": 41
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "getField",
                                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                            "line": 142,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 142,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 142,
                                                "char": 53
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "fieldName",
                                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                            "line": 143,
                                                            "char": 35
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "message",
                                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                                "line": 143,
                                                                "char": 45
                                                            },
                                                            "name": "getField",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                            "line": 143,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 143,
                                                        "char": 57
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable-append",
                                                                    "operator": "assign",
                                                                    "variable": "filtered",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "message",
                                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                                        "line": 144,
                                                                        "char": 49
                                                                    },
                                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                                    "line": 144,
                                                                    "char": 49
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                            "line": 145,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 146,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 147,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 148,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 150,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "filtered",
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 150,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 151,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Filters the message collection by field name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 127,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 127,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 126,
                    "last-line": 161,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "jsonSerialize",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "message",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 164,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 165,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "records",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 165,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 167,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "records",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 167,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 167,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 169,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 169,
                                    "char": 29
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "messages",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 169,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 169,
                                "char": 39
                            },
                            "value": "message",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "message",
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 170,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 170,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 170,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 170,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "method_exists",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "message",
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 170,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 170,
                                                    "char": 65
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "jsonSerialize",
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 170,
                                                        "char": 80
                                                    },
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 170,
                                                    "char": 80
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 170,
                                            "char": 82
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 170,
                                        "char": 82
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "records",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "message",
                                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                            "line": 171,
                                                            "char": 41
                                                        },
                                                        "name": "jsonSerialize",
                                                        "call-type": 3,
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 171,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 171,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 172,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "records",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "message",
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 173,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 173,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 174,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 175,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 177,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "records",
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 177,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 178,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns serialised message objects as array for json_encode. Calls\n     * jsonSerialize on each object if present\n     *\n     *```php\n     * $data = $messages->jsonSerialize();\n     * echo json_encode($data);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 163,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 163,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 162,
                    "last-line": 182,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "key",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 185,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "position",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 185,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 185,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 186,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current position\/key in the iterator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 184,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 184,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 183,
                    "last-line": 190,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "next",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-incr",
                                    "variable": "this",
                                    "property": "position",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 193,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 194,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Moves the internal iteration pointer to the next position\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 192,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 191,
                    "last-line": 206,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetExists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 207,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 209,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 209,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 209,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "index",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 209,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 209,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 209,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 210,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if an index exists\n     *\n     *```php\n     * var_dump(\n     *     isset($message[\"database\"])\n     * );\n     *```\n     *\n     * @param int index\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 208,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 208,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 207,
                    "last-line": 220,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetGet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 221,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "message",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 223,
                                    "char": 20
                                },
                                {
                                    "variable": "returnValue",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 223,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 223,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 225,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "message",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 225,
                                    "char": 49
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 225,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 225,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 225,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "index",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 225,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 225,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 225,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "returnValue",
                                            "expr": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 226,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 226,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 227,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 229,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "returnValue",
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 229,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 230,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets an attribute a message using the array syntax\n     *\n     *```php\n     * print_r(\n     *     $messages[0]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 222,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 222,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 221,
                    "last-line": 240,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetSet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 241,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 241,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "message",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 243,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 243,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 243,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 243,
                                "char": 37
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
                                                    "value": "The message must be an object",
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 244,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 244,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 244,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 245,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 247,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "messages",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "index",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 247,
                                            "char": 33
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "message",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 247,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 247,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 248,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets an attribute using the array-syntax\n     *\n     *```php\n     * $messages[0] = new \\Phalcon\\Messages\\Message(\"This is a message\");\n     *```\n     *\n     * @param \\Phalcon\\Messages\\Message message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 242,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 241,
                    "last-line": 256,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetUnset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 257,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 259,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 259,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 259,
                                        "char": 32
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "index",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 259,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 259,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 259,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_splice",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 260,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "messages",
                                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                        "line": 260,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 260,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 260,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "index",
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 260,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 260,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                    "line": 260,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                                "line": 260,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 260,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 261,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 262,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes a message from the list\n     *\n     *```php\n     * unset($message[\"database\"]);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 258,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 257,
                    "last-line": 266,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rewind",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "position",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 269,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 269,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 270,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Rewinds the internal iterator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 268,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 267,
                    "last-line": 274,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "valid",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 277,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 277,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 277,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 277,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                            "line": 277,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                        "line": 277,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                    "line": 277,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 277,
                                "char": 52
                            },
                            "file": "\/app\/phalcon\/Messages\/Messages.zep",
                            "line": 278,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if the current message in the iterator is valid\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Messages\/Messages.zep",
                                "line": 276,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Messages\/Messages.zep",
                        "line": 276,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Messages\/Messages.zep",
                    "line": 275,
                    "last-line": 279,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Messages\/Messages.zep",
            "line": 24,
            "char": 5
        },
        "file": "\/app\/phalcon\/Messages\/Messages.zep",
        "line": 24,
        "char": 5
    }
]