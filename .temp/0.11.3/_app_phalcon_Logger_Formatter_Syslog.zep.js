[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger\\Formatter",
        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Formatter\\AbstractFormatter",
                "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                "line": 13,
                "char": 47
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Item",
                "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Logger\\Formatter\\Syslog\n *\n * Prepares a message to be used in a Syslog backend\n *",
        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
        "line": 21,
        "char": 5
    },
    {
        "type": "class",
        "name": "Syslog",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractFormatter",
        "definition": {
            "methods": [
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
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                "line": 26,
                                "char": 38
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                            "line": 26,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "context",
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                    "line": 28,
                                    "char": 20
                                },
                                {
                                    "variable": "message",
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                    "line": 28,
                                    "char": 29
                                },
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                    "line": 28,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                            "line": 30,
                            "char": 11
                        },
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
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                            "line": 30,
                                            "char": 28
                                        },
                                        "name": "getMessage",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                        "line": 30,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                    "line": 30,
                                    "char": 41
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "type",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "item",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                            "line": 31,
                                            "char": 28
                                        },
                                        "name": "getType",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                        "line": 31,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                    "line": 31,
                                    "char": 38
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "context",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "item",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                            "line": 32,
                                            "char": 28
                                        },
                                        "name": "getContext",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                        "line": 32,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                    "line": 32,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                            "line": 34,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "context",
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                        "line": 34,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                    "line": 34,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                    "line": 34,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                "line": 34,
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
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                                    "line": 35,
                                                    "char": 32
                                                },
                                                "name": "interpolate",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "message",
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                                            "line": 35,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                                        "line": 35,
                                                        "char": 52
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "context",
                                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                                            "line": 35,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                                        "line": 35,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                                "line": 35,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                            "line": 35,
                                            "char": 62
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                    "line": 36,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                            "line": 38,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                            "line": 38,
                                            "char": 21
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                        "line": 38,
                                        "char": 21
                                    },
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                            "line": 38,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                        "line": 38,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                "line": 38,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                            "line": 39,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Applies a format to a message before sent it to the internal log\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                                "line": 27,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                        "line": 27,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
                    "line": 26,
                    "last-line": 40,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
            "line": 21,
            "char": 5
        },
        "file": "\/app\/phalcon\/Logger\/Formatter\/Syslog.zep",
        "line": 21,
        "char": 5
    }
]