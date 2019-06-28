[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Collection\\Behavior",
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Closure",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                "line": 13,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\CollectionInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                "line": 14,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Collection\\Behavior",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                "line": 15,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Collection\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                "line": 16,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
        "line": 23,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Collection\\Behavior\\Timestampable\n *\n * Allows to automatically update a model\u2019s attribute saving the\n * datetime when a record is created or updated\n *",
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
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
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
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
                                "value": "CollectionInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                "line": 29,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                            "line": 29,
                            "char": 69
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 31,
                                    "char": 20
                                },
                                {
                                    "variable": "timestamp",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 31,
                                    "char": 31
                                },
                                {
                                    "variable": "singleField",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 31,
                                    "char": 44
                                },
                                {
                                    "variable": "field",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 31,
                                    "char": 51
                                },
                                {
                                    "variable": "generator",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 31,
                                    "char": 62
                                },
                                {
                                    "variable": "format",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 31,
                                    "char": 70
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
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
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
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
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                "line": 36,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 36,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 36,
                                    "char": 41
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 36,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                "line": 36,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                        "line": 37,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 38,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
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
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
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
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                    "line": 40,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                "line": 40,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                        "line": 40,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 40,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                            "line": 41,
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
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                        "line": 41,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 41,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 41,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                "line": 41,
                                "char": 36
                            },
                            "statements": [
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
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                    "line": 46,
                                                    "char": 54
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "options",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                        "line": 46,
                                                        "char": 46
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "field",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                        "line": 46,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                    "line": 46,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                "line": 46,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 46,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                        "line": 46,
                                        "char": 54
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
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                            "line": 47,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                        "line": 47,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                "line": 47,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 48,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 50,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "timestamp",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                "line": 50,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 50,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 52,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "format",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 52,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                "line": 52,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "format",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                "line": 52,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 52,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                        "line": 52,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "timestamp",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "date",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "format",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                    "line": 56,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                "line": 56,
                                                                "char": 44
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                        "line": 56,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                    "line": 56,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 57,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "generator",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                    "line": 58,
                                                    "char": 56
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "options",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                        "line": 58,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "generator",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                        "line": 58,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                    "line": 58,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                "line": 58,
                                                "char": 56
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
                                                                "value": "generator",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                "line": 63,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                            "line": 63,
                                                            "char": 42
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "object",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                            "line": 63,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                        "line": 63,
                                                        "char": 51
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "instanceof",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "generator",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                    "line": 64,
                                                                    "char": 47
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "Closure",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                    "line": 64,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                "line": 64,
                                                                "char": 57
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "timestamp",
                                                                            "expr": {
                                                                                "type": "fcall",
                                                                                "name": "call_user_func",
                                                                                "call-type": 1,
                                                                                "parameters": [
                                                                                    {
                                                                                        "parameter": {
                                                                                            "type": "variable",
                                                                                            "value": "generator",
                                                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                                            "line": 65,
                                                                                            "char": 69
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                                        "line": 65,
                                                                                        "char": 69
                                                                                    }
                                                                                ],
                                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                                "line": 65,
                                                                                "char": 70
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                            "line": 65,
                                                                            "char": 70
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                    "line": 66,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                            "line": 67,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                    "line": 68,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 69,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 74,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "timestamp",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 74,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 74,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                        "line": 74,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "timestamp",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "time",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                        "line": 75,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                    "line": 75,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 76,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 81,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                "line": 81,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 81,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 81,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                        "line": 81,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                "line": 82,
                                                "char": 42
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
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                            "line": 83,
                                                            "char": 27
                                                        },
                                                        "name": "writeAttribute",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "singleField",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                    "line": 83,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                "line": 83,
                                                                "char": 54
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "timestamp",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                    "line": 83,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                                "line": 83,
                                                                "char": 65
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                        "line": 83,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                    "line": 84,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 85,
                                            "char": 13
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
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                    "line": 86,
                                                    "char": 23
                                                },
                                                "name": "writeAttribute",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                            "line": 86,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                        "line": 86,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "timestamp",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                            "line": 86,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                        "line": 86,
                                                        "char": 55
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                                "line": 86,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                            "line": 87,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                                    "line": 88,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                            "line": 89,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Listens for notifications from the models manager\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
                    "line": 29,
                    "last-line": 90,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
            "line": 24,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior\/Timestampable.zep",
        "line": 24,
        "char": 5
    }
]