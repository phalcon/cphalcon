[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger\\Formatter",
        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Formatter\\Formatter",
                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                "line": 13,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Item",
                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Logger\\Formatter\\Line\n *\n * Formats messages using an one-line string\n *",
        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
        "line": 21,
        "char": 5
    },
    {
        "type": "class",
        "name": "Line",
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
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 28,
                            "char": 31
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 28,
                            "char": 37
                        }
                    ],
                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                    "line": 34,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "format",
                    "docblock": "**\n     * Format applied to each message\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 35,
                            "char": 27
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 35,
                            "char": 33
                        }
                    ],
                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
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
                            "name": "format",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "[%date%][%type%] %message%",
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                "line": 40,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 40,
                            "char": 75
                        },
                        {
                            "type": "parameter",
                            "name": "dateFormat",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "D, d M y H:i:s O",
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                "line": 40,
                                "char": 113
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 40,
                            "char": 113
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
                                    "property": "format",
                                    "expr": {
                                        "type": "variable",
                                        "value": "format",
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                        "line": 42,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                    "line": 42,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 43,
                            "char": 11
                        },
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
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                        "line": 43,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                    "line": 43,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 44,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Logger\\Formatter\\Line construct\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                        "line": 41,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                    "line": 40,
                    "last-line": 48,
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
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                "line": 49,
                                "char": 38
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 49,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "format",
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                    "line": 51,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 53,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "format",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                            "line": 53,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "format",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                            "line": 53,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                        "line": 53,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                    "line": 53,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 58,
                            "char": 10
                        },
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
                                            "value": "format",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                            "line": 58,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                        "line": 58,
                                        "char": 25
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "%date%",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                            "line": 58,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                        "line": 58,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                "line": 58,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "format",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "str_replace",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "%date%",
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                            "line": 60,
                                                            "char": 23
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                        "line": 60,
                                                        "char": 23
                                                    },
                                                    {
                                                        "parameter": {
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
                                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                                            "line": 62,
                                                                            "char": 26
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "dateFormat",
                                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                                            "line": 62,
                                                                            "char": 37
                                                                        },
                                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                                        "line": 62,
                                                                        "char": 37
                                                                    },
                                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                                    "line": 62,
                                                                    "char": 37
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "item",
                                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                                            "line": 63,
                                                                            "char": 26
                                                                        },
                                                                        "name": "getTime",
                                                                        "call-type": 1,
                                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                                        "line": 64,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                                    "line": 64,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                            "line": 64,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                        "line": 64,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "format",
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                            "line": 66,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                        "line": 66,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                "line": 66,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                            "line": 66,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                    "line": 67,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 72,
                            "char": 10
                        },
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
                                            "value": "format",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                            "line": 72,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                        "line": 72,
                                        "char": 25
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "%type%",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                            "line": 72,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                        "line": 72,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                "line": 72,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "format",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "str_replace",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "%type%",
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                            "line": 73,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                        "line": 73,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "item",
                                                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                                "line": 73,
                                                                "char": 51
                                                            },
                                                            "name": "getName",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                            "line": 73,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                        "line": 73,
                                                        "char": 61
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "format",
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                            "line": 73,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                        "line": 73,
                                                        "char": 69
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                "line": 73,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                            "line": 73,
                                            "char": 70
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                    "line": 74,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 76,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "format",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "fcall",
                                            "name": "str_replace",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "%message%",
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                        "line": 76,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                    "line": 76,
                                                    "char": 43
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "item",
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                            "line": 76,
                                                            "char": 50
                                                        },
                                                        "name": "getMessage",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                        "line": 76,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                    "line": 76,
                                                    "char": 63
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "format",
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                        "line": 76,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                    "line": 76,
                                                    "char": 71
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                            "line": 76,
                                            "char": 73
                                        },
                                        "right": {
                                            "type": "constant",
                                            "value": "PHP_EOL",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                            "line": 76,
                                            "char": 82
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                        "line": 76,
                                        "char": 82
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                    "line": 76,
                                    "char": 82
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 78,
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
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                            "line": 78,
                                            "char": 24
                                        },
                                        "name": "getContext",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                        "line": 78,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                    "line": 78,
                                    "char": 40
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                    "line": 78,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                "line": 78,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                            "line": 79,
                                            "char": 25
                                        },
                                        "name": "interpolate",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "format",
                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                    "line": 80,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                "line": 80,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "item",
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                        "line": 81,
                                                        "char": 22
                                                    },
                                                    "name": "getContext",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                    "line": 82,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                                "line": 82,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                        "line": 82,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                    "line": 83,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 85,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "format",
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                "line": 85,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                            "line": 86,
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
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                                "line": 50,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                        "line": 50,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
                    "line": 49,
                    "last-line": 87,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
            "line": 21,
            "char": 5
        },
        "file": "\/app\/phalcon\/Logger\/Formatter\/Line.zep",
        "line": 21,
        "char": 5
    }
]