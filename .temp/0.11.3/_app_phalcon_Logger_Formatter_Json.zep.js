[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger\\Formatter",
        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Formatter\\AbstractFormatter",
                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                "line": 13,
                "char": 47
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Item",
                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Logger\\Formatter\\Json\n *\n * Formats messages using JSON encoding\n *",
        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
        "line": 21,
        "char": 5
    },
    {
        "type": "class",
        "name": "Json",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractFormatter",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "dateFormat",
                    "docblock": "**\n     * Default date format\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                            "line": 28,
                            "char": 31
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                            "line": 28,
                            "char": 37
                        }
                    ],
                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                    "line": 32,
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
                            "name": "dateFormat",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "D, d M y H:i:s O",
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                "line": 33,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                            "line": 33,
                            "char": 69
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
                                    "property": "dateFormat",
                                    "expr": {
                                        "type": "variable",
                                        "value": "dateFormat",
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                        "line": 35,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                    "line": 35,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                            "line": 36,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Logger\\Formatter\\Json construct\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                        "line": 34,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                    "line": 33,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "format",
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
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                "line": 41,
                                "char": 38
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                            "line": 41,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "message",
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                    "line": 43,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                            "line": 45,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "item",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                            "line": 45,
                                            "char": 24
                                        },
                                        "name": "getContext",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                        "line": 45,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                    "line": 45,
                                    "char": 40
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                    "line": 45,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                "line": 45,
                                "char": 48
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
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                    "line": 46,
                                                    "char": 32
                                                },
                                                "name": "interpolate",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "item",
                                                                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                                "line": 47,
                                                                "char": 22
                                                            },
                                                            "name": "getMessage",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                            "line": 47,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                        "line": 47,
                                                        "char": 35
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "item",
                                                                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                                "line": 48,
                                                                "char": 22
                                                            },
                                                            "name": "getContext",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                            "line": 49,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                        "line": 49,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                "line": 49,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                            "line": 49,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                    "line": 50,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
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
                                                    "value": "item",
                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                    "line": 51,
                                                    "char": 32
                                                },
                                                "name": "getMessage",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                "line": 51,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                            "line": 51,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                    "line": 52,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                            "line": 54,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "fcall",
                                    "name": "json_encode",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "type",
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                            "line": 56,
                                                            "char": 27
                                                        },
                                                        "value": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "item",
                                                                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                                "line": 56,
                                                                "char": 34
                                                            },
                                                            "name": "getName",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                            "line": 56,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                        "line": 56,
                                                        "char": 44
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "message",
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                            "line": 57,
                                                            "char": 27
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "message",
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                            "line": 57,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                        "line": 57,
                                                        "char": 36
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "timestamp",
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                            "line": 58,
                                                            "char": 27
                                                        },
                                                        "value": {
                                                            "type": "fcall",
                                                            "name": "date",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                                            "line": 58,
                                                                            "char": 39
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "dateFormat",
                                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                                            "line": 58,
                                                                            "char": 50
                                                                        },
                                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                                        "line": 58,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                                    "line": 58,
                                                                    "char": 50
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "item",
                                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                                            "line": 58,
                                                                            "char": 57
                                                                        },
                                                                        "name": "getTime",
                                                                        "call-type": 1,
                                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                                        "line": 58,
                                                                        "char": 67
                                                                    },
                                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                                    "line": 58,
                                                                    "char": 67
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                            "line": 59,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                        "line": 59,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                                "line": 60,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                            "line": 60,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                    "line": 60,
                                    "char": 11
                                },
                                "right": {
                                    "type": "constant",
                                    "value": "PHP_EOL",
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                    "line": 60,
                                    "char": 20
                                },
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                "line": 60,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                            "line": 61,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Applies a format to a message before sent it to the internal log\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                                "line": 42,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                        "line": 42,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
                    "line": 41,
                    "last-line": 62,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
            "line": 21,
            "char": 5
        },
        "file": "\/app\/phalcon\/Logger\/Formatter\/Json.zep",
        "line": 21,
        "char": 5
    }
]