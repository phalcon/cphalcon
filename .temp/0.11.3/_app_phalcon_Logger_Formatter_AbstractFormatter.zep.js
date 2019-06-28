[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger\\Formatter",
        "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Logger",
                "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
        "line": 15,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractFormatter",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "FormatterInterface",
                "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                "line": 16,
                "char": 1
            }
        ],
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "interpolate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                            "line": 24,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                "line": 24,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                            "line": 24,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                    "line": 26,
                                    "char": 16
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                    "line": 26,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                            "line": 27,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "replace",
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                    "line": 27,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                            "line": 29,
                            "char": 10
                        },
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
                                            "value": "context",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                            "line": 29,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                        "line": 29,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                        "line": 29,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                    "line": 29,
                                    "char": 37
                                },
                                "right": {
                                    "type": "greater",
                                    "left": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "context",
                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                    "line": 29,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                "line": 29,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                        "line": 29,
                                        "char": 54
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                        "line": 29,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                    "line": 29,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                "line": 29,
                                "char": 58
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "replace",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                "line": 30,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                            "line": 30,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                    "line": 32,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "context",
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                        "line": 32,
                                        "char": 39
                                    },
                                    "key": "key",
                                    "value": "value",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "replace",
                                                    "index-expr": [
                                                        {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "{",
                                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                                    "line": 33,
                                                                    "char": 31
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "key",
                                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                                    "line": 33,
                                                                    "char": 37
                                                                },
                                                                "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                                "line": 33,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "}",
                                                                "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                                "line": 33,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                            "line": 33,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                        "line": 33,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                    "line": 33,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                            "line": 34,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                    "line": 36,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "message",
                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                    "line": 36,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                "line": 36,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "replace",
                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                    "line": 36,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                                "line": 36,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                        "line": 36,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                    "line": 37,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                            "line": 39,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "message",
                                "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                                "line": 39,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                            "line": 40,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Interpolates context values into the message placeholders\n     *\n     * @see http:\/\/www.php-fig.org\/psr\/psr-3\/ Section 1.2 Message\n     * @param string $message\n     * @param array $context\n     *",
                    "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
                    "line": 24,
                    "last-line": 41,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
            "line": 15,
            "char": 14
        },
        "file": "\/app\/phalcon\/Logger\/Formatter\/AbstractFormatter.zep",
        "line": 15,
        "char": 14
    }
]