[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\Behavior",
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Closure",
                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                "line": 13,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                "line": 14,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Behavior",
                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                "line": 15,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                "line": 16,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
        "line": 23,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Behavior\\Timestampable\n *\n * Allows to automatically update a model\u2019s attribute saving the datetime when a\n * record is created or updated\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
        "line": 24,
        "char": 5
    },
    {
        "type": "class",
        "name": "Timestampable",
        "abstract": 0,
        "final": 0,
        "extends": "Behavior",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notify",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 29,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                "line": 29,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 29,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 31,
                                    "char": 20
                                },
                                {
                                    "variable": "timestamp",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 31,
                                    "char": 31
                                },
                                {
                                    "variable": "singleField",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 31,
                                    "char": 44
                                },
                                {
                                    "variable": "field",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 31,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 36,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 36,
                                        "char": 17
                                    },
                                    "name": "mustTakeAction",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 36,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                            "line": 36,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 36,
                                    "char": 41
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 36,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                "line": 36,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 37,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 38,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 40,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "options",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                            "line": 40,
                                            "char": 28
                                        },
                                        "name": "getOptions",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                    "line": 40,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 40,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 40,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 40,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 42,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 42,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 42,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 42,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                "line": 42,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 44,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 49,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "field",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                            "line": 49,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 49,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 49,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                            "line": 49,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 49,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 49,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                "line": 49,
                                "char": 50
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
                                                    "value": "The option 'field' is required",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                    "line": 50,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 50,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 50,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 51,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 53,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "timestamp",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                            "line": 53,
                                            "char": 30
                                        },
                                        "name": "getTimestamp",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                    "line": 53,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 53,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 53,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 53,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 59,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "field",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                            "line": 59,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 59,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 59,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 59,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                "line": 59,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "field",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 60,
                                        "char": 38
                                    },
                                    "value": "singleField",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                    "line": 61,
                                                    "char": 23
                                                },
                                                "name": "writeAttribute",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "singleField",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                            "line": 61,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                        "line": 61,
                                                        "char": 50
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "timestamp",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                            "line": 61,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                        "line": 61,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 61,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                            "line": 62,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 63,
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
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                            "line": 64,
                                            "char": 19
                                        },
                                        "name": "writeAttribute",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                    "line": 64,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 64,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "timestamp",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                    "line": 64,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 64,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 64,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 65,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 66,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Listens for notifications from the models manager\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                    "line": 29,
                    "last-line": 68,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "getTimestamp",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 68,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "format",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 70,
                                    "char": 19
                                },
                                {
                                    "variable": "generator",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 70,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 72,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "format",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 72,
                                    "char": 42
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 72,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "format",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 72,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 72,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                "line": 72,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "date",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "format",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                    "line": 76,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 76,
                                                "char": 31
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 76,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 77,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 79,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "generator",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 79,
                                    "char": 48
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 79,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "generator",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 79,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 79,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                "line": 79,
                                "char": 48
                            },
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
                                                    "value": "generator",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                    "line": 83,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 83,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 83,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                            "line": 83,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "instanceof",
                                            "left": {
                                                "type": "variable",
                                                "value": "generator",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 83,
                                                "char": 65
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "Closure",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 83,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                            "line": 83,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                        "line": 83,
                                        "char": 75
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "call_user_func",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "generator",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                            "line": 84,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                        "line": 84,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                                "line": 84,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                            "line": 85,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                    "line": 86,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 91,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "time",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                                "line": 91,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                            "line": 92,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
                    "line": 68,
                    "last-line": 93,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
            "line": 24,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior\/Timestampable.zep",
        "line": 24,
        "char": 5
    }
]