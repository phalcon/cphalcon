[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/Dialect.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db",
        "file": "\/app\/phalcon\/Db\/Dialect.zep",
        "line": 16,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This is the base class to each database dialect. This implements\n * common methods to transform intermediate code into its RDBMS related syntax\n *",
        "file": "\/app\/phalcon\/Db\/Dialect.zep",
        "line": 17,
        "char": 8
    },
    {
        "type": "class",
        "name": "Dialect",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "DialectInterface",
                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                "line": 18,
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
                    "name": "escapeChar",
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 21,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "customFunctions",
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
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
                    "name": "createSavepoint",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 26,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "SAVEPOINT ",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 28,
                                    "char": 27
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 28,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 28,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 29,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generate SQL to create a new savepoint\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 27,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 27,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 26,
                    "last-line": 33,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "escape",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "str",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 34,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 34,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 34,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "parts",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 36,
                                    "char": 18
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 36,
                                    "char": 23
                                },
                                {
                                    "variable": "part",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 36,
                                    "char": 29
                                },
                                {
                                    "variable": "newParts",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 36,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 38,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "globals_get",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "db.escape_identifiers",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 38,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 38,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 38,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 38,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "str",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 39,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 40,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 42,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "escapeChar",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 42,
                                    "char": 24
                                },
                                "right": {
                                    "type": "string",
                                    "value": "",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 42,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 42,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "escapeChar",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 43,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "escapeChar",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 43,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 43,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 43,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 43,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 44,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 46,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "memstr",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "str",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 46,
                                                "char": 23
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 46,
                                            "char": 23
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": ".",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 46,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 46,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 46,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 46,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "escapeChar",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 47,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 47,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 47,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "str",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 47,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "*",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 47,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 47,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 47,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "escapeChar",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 48,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "fcall",
                                                        "name": "str_replace",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "escapeChar",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 48,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 48,
                                                                "char": 59
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "escapeChar",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 48,
                                                                        "char": 72
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "escapeChar",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 48,
                                                                        "char": 84
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 48,
                                                                    "char": 84
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 48,
                                                                "char": 84
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "str",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 48,
                                                                    "char": 89
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 48,
                                                                "char": 89
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 48,
                                                        "char": 91
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 48,
                                                    "char": 91
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 48,
                                                    "char": 103
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 48,
                                                "char": 103
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 49,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 51,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "str",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 51,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 52,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 54,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "parts",
                                    "expr": {
                                        "type": "cast",
                                        "left": "array",
                                        "right": {
                                            "type": "fcall",
                                            "name": "explode",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": ".",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 54,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 54,
                                                    "char": 38
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "fcall",
                                                        "name": "trim",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "str",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 54,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 54,
                                                                "char": 48
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "escapeChar",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 54,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 54,
                                                                "char": 60
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 54,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 54,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 54,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 54,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 54,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 56,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "newParts",
                                    "expr": {
                                        "type": "variable",
                                        "value": "parts",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 56,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 56,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 58,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "parts",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 58,
                                "char": 32
                            },
                            "key": "key",
                            "value": "part",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "or",
                                        "left": {
                                            "type": "or",
                                            "left": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 59,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 59,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 59,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "part",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 59,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 59,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 59,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 59,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "part",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 59,
                                                "char": 52
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "*",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 59,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 59,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 59,
                                        "char": 56
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 61,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 63,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "newParts",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 63,
                                                    "char": 29
                                                }
                                            ],
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "escapeChar",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 63,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "fcall",
                                                        "name": "str_replace",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "escapeChar",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 63,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 63,
                                                                "char": 68
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "escapeChar",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 63,
                                                                        "char": 81
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "escapeChar",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 63,
                                                                        "char": 93
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 63,
                                                                    "char": 93
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 63,
                                                                "char": 93
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "part",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 63,
                                                                    "char": 99
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 63,
                                                                "char": 99
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 63,
                                                        "char": 101
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 63,
                                                    "char": 101
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 63,
                                                    "char": 113
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 63,
                                                "char": 113
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 63,
                                            "char": 113
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 64,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 66,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "implode",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": ".",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 66,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 66,
                                        "char": 25
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "newParts",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 66,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 66,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 66,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 67,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Escape identifiers\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 35,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 35,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 34,
                    "last-line": 71,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "escapeSchema",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "str",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 72,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 72,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 72,
                            "char": 77
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "globals_get",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "db.escape_identifiers",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 74,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 74,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 74,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 74,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "str",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 75,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 76,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 78,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "escapeChar",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 78,
                                    "char": 24
                                },
                                "right": {
                                    "type": "string",
                                    "value": "",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 78,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 78,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "escapeChar",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 79,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "escapeChar",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 79,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 79,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 79,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 79,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 80,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 82,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "variable",
                                        "value": "escapeChar",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 82,
                                        "char": 27
                                    },
                                    "right": {
                                        "type": "fcall",
                                        "name": "trim",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "str",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 82,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 82,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 82,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 82,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 82,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 82,
                                    "char": 51
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "escapeChar",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 82,
                                    "char": 63
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 82,
                                "char": 63
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 83,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Escape Schema\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 73,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 73,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 72,
                    "last-line": 93,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "forUpdate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sqlQuery",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 94,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "variable",
                                    "value": "sqlQuery",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 96,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": " FOR UPDATE",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 96,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 96,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 97,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a SQL modified with a FOR UPDATE clause\n     *\n     *```php\n     * $sql = $dialect->forUpdate(\"SELECT * FROM robots\");\n     *\n     * echo $sql; \/\/ SELECT * FROM robots FOR UPDATE\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 95,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 95,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 94,
                    "last-line": 110,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "getColumnList",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "columnList",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 111,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 111,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 111,
                            "char": 84
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 111,
                                "char": 103
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 111,
                            "char": 103
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 113,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 114,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 114,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 116,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "columns",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 116,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 116,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 118,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "columnList",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 118,
                                "char": 34
                            },
                            "value": "column",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "columns",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 119,
                                                    "char": 34
                                                },
                                                "name": "getSqlColumn",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "column",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 119,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 119,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 119,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 119,
                                                        "char": 66
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 119,
                                                            "char": 78
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 119,
                                                        "char": 78
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 119,
                                                "char": 79
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 119,
                                            "char": 79
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 120,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 122,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "join",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": ", ",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 122,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 122,
                                        "char": 23
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "columns",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 122,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 122,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 122,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 123,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets a list of columns with escaped identifiers\n     *\n     * ```php\n     * echo $dialect->getColumnList(\n     *     [\n     *         \"column1\",\n     *         \"column\",\n     *     ]\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 112,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 112,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 111,
                    "last-line": 127,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCustomFunctions",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 130,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "customFunctions",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 130,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 130,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 131,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns registered functions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 129,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 129,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 128,
                    "last-line": 135,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "getSqlColumn",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "column",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 136,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 136,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 136,
                            "char": 76
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 136,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 136,
                            "char": 95
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "columnExpression",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 138,
                                    "char": 29
                                },
                                {
                                    "variable": "columnAlias",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 138,
                                    "char": 42
                                },
                                {
                                    "variable": "columnField",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 138,
                                    "char": 55
                                },
                                {
                                    "variable": "columnDomain",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 138,
                                    "char": 69
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 140,
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
                                        "value": "column",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 140,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 140,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 140,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 140,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 141,
                                            "char": 25
                                        },
                                        "name": "prepareQualified",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 141,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 141,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 141,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 141,
                                                "char": 55
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 141,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 141,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 141,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 142,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 144,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 144,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 144,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 144,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 144,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 144,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "columnField",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 148,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 148,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 148,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 148,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 150,
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
                                                "value": "columnField",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 150,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 150,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 150,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 150,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "columnExpression",
                                                    "expr": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 152,
                                                                    "char": 25
                                                                },
                                                                "value": {
                                                                    "type": "string",
                                                                    "value": "scalar",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 152,
                                                                    "char": 33
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 152,
                                                                "char": 33
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 153,
                                                                    "char": 26
                                                                },
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "columnField",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 154,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 154,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 154,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 154,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 155,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "columnField",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 155,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "*",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 155,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 155,
                                                "char": 39
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "columnExpression",
                                                            "expr": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "key": {
                                                                            "type": "string",
                                                                            "value": "type",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 157,
                                                                            "char": 25
                                                                        },
                                                                        "value": {
                                                                            "type": "string",
                                                                            "value": "all",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 158,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 158,
                                                                        "char": 17
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 158,
                                                                "char": 18
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 158,
                                                            "char": 18
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 159,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 159,
                                            "char": 18
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "columnExpression",
                                                    "expr": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 161,
                                                                    "char": 25
                                                                },
                                                                "value": {
                                                                    "type": "string",
                                                                    "value": "qualified",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 161,
                                                                    "char": 36
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 161,
                                                                "char": 36
                                                            },
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 162,
                                                                    "char": 25
                                                                },
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "columnField",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 163,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 163,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 163,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 163,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 164,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 169,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "columnDomain",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 169,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 169,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 169,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 169,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 169,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "columnDomain",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 169,
                                                "char": 63
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 169,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 169,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 169,
                                        "char": 66
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "columnExpression",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "domain",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 170,
                                                            "char": 44
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "columnDomain",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 170,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 170,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 171,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 176,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "columnAlias",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 176,
                                                "char": 46
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 176,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "2",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 176,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 176,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 176,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "columnAlias",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 176,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 176,
                                        "char": 60
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "columnExpression",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "sqlAlias",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 177,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "columnAlias",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 177,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 177,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 178,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 179,
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
                                            "variable": "columnExpression",
                                            "expr": {
                                                "type": "variable",
                                                "value": "column",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 180,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 180,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 181,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 186,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "column",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 186,
                                            "char": 27
                                        },
                                        "name": "getSqlExpression",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "columnExpression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 187,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 187,
                                                "char": 29
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 188,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 188,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "bindCounts",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 190,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 190,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 190,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 190,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 195,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "columnAlias",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 195,
                                        "char": 59
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "columnExpression",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 195,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "sqlAlias",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 195,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 195,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 195,
                                    "char": 59
                                },
                                "right": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "columnAlias",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 195,
                                        "char": 104
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "columnExpression",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 195,
                                            "char": 96
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "alias",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 195,
                                            "char": 102
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 195,
                                        "char": 104
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 195,
                                    "char": 104
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 195,
                                "char": 104
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 196,
                                            "char": 25
                                        },
                                        "name": "prepareColumnAlias",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 196,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 196,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "columnAlias",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 196,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 196,
                                                "char": 64
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 196,
                                                    "char": 76
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 196,
                                                "char": 76
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 196,
                                        "char": 77
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 197,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 199,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 199,
                                    "char": 21
                                },
                                "name": "prepareColumnAlias",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 199,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 199,
                                        "char": 47
                                    },
                                    {
                                        "parameter": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 199,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 199,
                                        "char": 53
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "escapeChar",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 199,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 199,
                                        "char": 65
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 199,
                                "char": 66
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 200,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve Column expressions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 137,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 137,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 136,
                    "last-line": 204,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSqlExpression",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 205,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 205,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 205,
                            "char": 81
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 205,
                                "char": 100
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 205,
                            "char": 100
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "i",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 207,
                                    "char": 14
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 208,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 208,
                                    "char": 17
                                },
                                {
                                    "variable": "times",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 208,
                                    "char": 24
                                },
                                {
                                    "variable": "postTimes",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 208,
                                    "char": 35
                                },
                                {
                                    "variable": "rawValue",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 208,
                                    "char": 45
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 208,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 209,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "placeholders",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 209,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 211,
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
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 211,
                                            "char": 51
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "expression",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 211,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 211,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 211,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 211,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 211,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 211,
                                "char": 51
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
                                                    "value": "Invalid SQL expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 212,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 212,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 212,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 213,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 215,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "type",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 215,
                                "char": 21
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "scalar",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 220,
                                        "char": 24
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 221,
                                                    "char": 29
                                                },
                                                "name": "getSqlExpressionScalar",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 222,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 222,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 223,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 223,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 225,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 225,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 225,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 230,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 230,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 230,
                                        "char": 24
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 231,
                                                    "char": 29
                                                },
                                                "name": "getSqlExpressionObject",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 232,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 232,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 233,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 233,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 235,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 235,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 235,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 240,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 240,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "qualified",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 240,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 241,
                                                    "char": 29
                                                },
                                                "name": "getSqlExpressionQualified",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 241,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 241,
                                                        "char": 66
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 241,
                                                            "char": 78
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 241,
                                                        "char": 78
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 241,
                                                "char": 79
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 246,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 246,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "literal",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 246,
                                        "char": 25
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 247,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 247,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 247,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 249,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 249,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "placeholder",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 249,
                                        "char": 29
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "times",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 250,
                                                    "char": 51
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "expression",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 250,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "times",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 250,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 250,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 250,
                                                "char": 51
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "placeholders",
                                                            "expr": {
                                                                "type": "empty-array",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 252,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 252,
                                                            "char": 42
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "rawValue",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "expression",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 253,
                                                                    "char": 46
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "rawValue",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 253,
                                                                    "char": 55
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 253,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 253,
                                                            "char": 56
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "value",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "expression",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 254,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 254,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 254,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 254,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 256,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fetch",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "postTimes",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 256,
                                                            "char": 62
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "bindCounts",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 256,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "rawValue",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 256,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 256,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 256,
                                                        "char": 62
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "times",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "postTimes",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 257,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 257,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 258,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 260,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "range",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "1",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 260,
                                                                    "char": 37
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 260,
                                                                "char": 37
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "times",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 260,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 260,
                                                                "char": 44
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 260,
                                                        "char": 46
                                                    },
                                                    "value": "i",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable-append",
                                                                    "operator": "assign",
                                                                    "variable": "placeholders",
                                                                    "expr": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "value",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 261,
                                                                            "char": 52
                                                                        },
                                                                        "right": {
                                                                            "type": "list",
                                                                            "left": {
                                                                                "type": "sub",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "i",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                    "line": 261,
                                                                                    "char": 57
                                                                                },
                                                                                "right": {
                                                                                    "type": "int",
                                                                                    "value": "1",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                    "line": 261,
                                                                                    "char": 60
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                "line": 261,
                                                                                "char": 60
                                                                            },
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 261,
                                                                            "char": 61
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 261,
                                                                        "char": 61
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 261,
                                                                    "char": 61
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 262,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 264,
                                                    "char": 26
                                                },
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "join",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": ", ",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 264,
                                                                    "char": 35
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 264,
                                                                "char": 35
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "placeholders",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 264,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 264,
                                                                "char": 49
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 264,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 265,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 267,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 267,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 267,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 267,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 272,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 272,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "binary-op",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 272,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 273,
                                                    "char": 29
                                                },
                                                "name": "getSqlExpressionBinaryOperations",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 274,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 274,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 275,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 275,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 277,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 277,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 277,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 282,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 282,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "unary-op",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 282,
                                        "char": 26
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 283,
                                                    "char": 29
                                                },
                                                "name": "getSqlExpressionUnaryOperations",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 284,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 284,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 285,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 285,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 287,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 287,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 287,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 292,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 292,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "parentheses",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 292,
                                        "char": 29
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "(",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 293,
                                                        "char": 26
                                                    },
                                                    "right": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 293,
                                                            "char": 33
                                                        },
                                                        "name": "getSqlExpression",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "expression",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 293,
                                                                        "char": 61
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "left",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 293,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 293,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 293,
                                                                "char": 67
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "escapeChar",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 293,
                                                                    "char": 79
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 293,
                                                                "char": 79
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "bindCounts",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 293,
                                                                    "char": 91
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 293,
                                                                "char": 91
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 293,
                                                        "char": 93
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 293,
                                                    "char": 93
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ")",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 293,
                                                    "char": 96
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 293,
                                                "char": 96
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 298,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 298,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "functionCall",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 298,
                                        "char": 30
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 299,
                                                    "char": 29
                                                },
                                                "name": "getSqlExpressionFunctionCall",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 300,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 300,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 301,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 301,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 303,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 303,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 303,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 308,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 308,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "list",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 308,
                                        "char": 22
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 309,
                                                    "char": 29
                                                },
                                                "name": "getSqlExpressionList",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 310,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 310,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 311,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 311,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 313,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 313,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 313,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 318,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 318,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "all",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 318,
                                        "char": 21
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 319,
                                                    "char": 29
                                                },
                                                "name": "getSqlExpressionAll",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 319,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 319,
                                                        "char": 60
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 319,
                                                            "char": 72
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 319,
                                                        "char": 72
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 319,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 324,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 324,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "select",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 324,
                                        "char": 24
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "(",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 325,
                                                        "char": 26
                                                    },
                                                    "right": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 325,
                                                            "char": 33
                                                        },
                                                        "name": "select",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "expression",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 325,
                                                                        "char": 51
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 325,
                                                                        "char": 57
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 325,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 325,
                                                                "char": 58
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 325,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 325,
                                                    "char": 60
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ")",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 325,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 325,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 330,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 330,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "cast",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 330,
                                        "char": 22
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 331,
                                                    "char": 29
                                                },
                                                "name": "getSqlExpressionCastValue",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 332,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 332,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 333,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 333,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 335,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 335,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 335,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 340,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 340,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "convert",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 340,
                                        "char": 25
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 341,
                                                    "char": 29
                                                },
                                                "name": "getSqlExpressionConvertValue",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 342,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 342,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 343,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 343,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 345,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 345,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 345,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 347,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 347,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "case",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 347,
                                        "char": 22
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 348,
                                                    "char": 29
                                                },
                                                "name": "getSqlExpressionCase",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 349,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 349,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 350,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 350,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 352,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 352,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 352,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 353,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 353,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 358,
                            "char": 13
                        },
                        {
                            "type": "throw",
                            "expr": {
                                "type": "new",
                                "class": "Exception",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "Invalid SQL expression type '",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 358,
                                                    "char": 59
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 358,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 358,
                                                "char": 66
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "'",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 358,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 358,
                                            "char": 69
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 358,
                                        "char": 69
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 358,
                                "char": 70
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 359,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Transforms an intermediate representation for an expression into a database system valid expression\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 206,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 206,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 205,
                    "last-line": 364,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "getSqlTable",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "table",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 365,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 365,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 365,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "tableName",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 367,
                                    "char": 22
                                },
                                {
                                    "variable": "schemaName",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 367,
                                    "char": 34
                                },
                                {
                                    "variable": "aliasName",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 367,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 369,
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
                                        "value": "table",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 369,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 369,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 369,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 369,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "tableName",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "table",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 374,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 374,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 374,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 374,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 379,
                                    "char": 17
                                },
                                {
                                    "type": "fetch",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "schemaName",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 379,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "table",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 379,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 379,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 379,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 379,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 384,
                                    "char": 17
                                },
                                {
                                    "type": "fetch",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "aliasName",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 384,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "table",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 384,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "2",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 384,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 384,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 384,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 386,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 386,
                                            "char": 25
                                        },
                                        "name": "prepareTable",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "tableName",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 387,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 387,
                                                "char": 26
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "schemaName",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 388,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 388,
                                                "char": 27
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "aliasName",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 389,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 389,
                                                "char": 26
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 391,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 391,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 391,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 392,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 394,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 394,
                                    "char": 21
                                },
                                "name": "escape",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "table",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 394,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 394,
                                        "char": 34
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "escapeChar",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 394,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 394,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 394,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 395,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Transform an intermediate representation of a schema\/table into a\n     * database system valid expression\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 366,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 366,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 365,
                    "last-line": 413,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "limit",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "sqlQuery",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 414,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "number",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 414,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "number",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 416,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 416,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 416,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 416,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "sqlQuery",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": " LIMIT ",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 417,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "number",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 417,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 417,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 417,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 417,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 417,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 419,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "number",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 419,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 419,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 419,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 419,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "strlen",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "number",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 419,
                                                            "char": 48
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 419,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 419,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 419,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 419,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 419,
                                        "char": 53
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "sqlQuery",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": " OFFSET ",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 420,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "number",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 420,
                                                                "char": 49
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 420,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 420,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 420,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 420,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 421,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 423,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "sqlQuery",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 423,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 424,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 426,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "variable",
                                        "value": "sqlQuery",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 426,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": " LIMIT ",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 426,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 426,
                                    "char": 35
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "number",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 426,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 426,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 427,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates the SQL for LIMIT clause\n     *\n     * ```php\n     * \/\/ SELECT * FROM robots LIMIT 10\n     * echo $dialect->limit(\n     *     \"SELECT * FROM robots\",\n     *     10\n     * );\n     *\n     * \/\/ SELECT * FROM robots LIMIT 10 OFFSET 50\n     * echo $dialect->limit(\n     *     \"SELECT * FROM robots\",\n     *     [10, 50]\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 415,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 415,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 414,
                    "last-line": 431,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerCustomFunction",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 432,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "customFunction",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 432,
                            "char": 80
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "customFunctions",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 434,
                                            "char": 39
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "customFunction",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 434,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 434,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 436,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 436,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 437,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Registers custom SQL functions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Dialect",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 433,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 433,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 433,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 432,
                    "last-line": 441,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "releaseSavepoint",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 442,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "RELEASE SAVEPOINT ",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 444,
                                    "char": 35
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 444,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 444,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 445,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generate SQL to release a savepoint\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 443,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 443,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 442,
                    "last-line": 449,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rollbackSavepoint",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 450,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "ROLLBACK TO SAVEPOINT ",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 452,
                                    "char": 39
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 452,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 452,
                                "char": 45
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 453,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generate SQL to rollback a savepoint\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 451,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 451,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 450,
                    "last-line": 457,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "select",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 458,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "tables",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 460,
                                    "char": 19
                                },
                                {
                                    "variable": "columns",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 460,
                                    "char": 28
                                },
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 460,
                                    "char": 33
                                },
                                {
                                    "variable": "distinct",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 460,
                                    "char": 43
                                },
                                {
                                    "variable": "joins",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 460,
                                    "char": 50
                                },
                                {
                                    "variable": "where",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 460,
                                    "char": 57
                                },
                                {
                                    "variable": "escapeChar",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 460,
                                    "char": 69
                                },
                                {
                                    "variable": "groupBy",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 460,
                                    "char": 78
                                },
                                {
                                    "variable": "having",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 461,
                                    "char": 19
                                },
                                {
                                    "variable": "orderBy",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 461,
                                    "char": 28
                                },
                                {
                                    "variable": "limit",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 461,
                                    "char": 35
                                },
                                {
                                    "variable": "forUpdate",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 461,
                                    "char": 46
                                },
                                {
                                    "variable": "bindCounts",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 461,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 463,
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
                                            "value": "tables",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 463,
                                            "char": 55
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 463,
                                                "char": 46
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "tables",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 463,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 463,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 463,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 463,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 463,
                                "char": 55
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
                                                    "value": "The index 'tables' is required in the definition array",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 466,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 466,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 466,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 467,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 469,
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
                                            "value": "columns",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 469,
                                            "char": 57
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 469,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "columns",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 469,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 469,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 469,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 469,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 469,
                                "char": 57
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
                                                    "value": "The index 'columns' is required in the definition array",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 472,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 472,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 472,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 473,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 475,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "distinct",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 475,
                                    "char": 49
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 475,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "distinct",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 475,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 475,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 475,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "distinct",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 476,
                                        "char": 25
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "sql",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "SELECT DISTINCT",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 477,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 477,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 478,
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
                                                    "variable": "sql",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "SELECT ALL",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 479,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 479,
                                                    "char": 37
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 480,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 481,
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
                                            "variable": "sql",
                                            "expr": {
                                                "type": "string",
                                                "value": "SELECT",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 482,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 482,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 483,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 485,
                            "char": 13
                        },
                        {
                            "type": "fetch",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "bindCounts",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 485,
                                    "char": 49
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 485,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "bindCounts",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 485,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 485,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 485,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 487,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escapeChar",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 487,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "escapeChar",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 487,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 487,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 487,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 492,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "sql",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": " ",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 492,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 492,
                                                "char": 28
                                            },
                                            "name": "getColumnList",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "columns",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 492,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 492,
                                                    "char": 50
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "escapeChar",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 492,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 492,
                                                    "char": 62
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "bindCounts",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 492,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 492,
                                                    "char": 74
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 492,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 492,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 492,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 497,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "sql",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": " ",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 497,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 497,
                                                "char": 28
                                            },
                                            "name": "getSqlExpressionFrom",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "tables",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 497,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 497,
                                                    "char": 56
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "escapeChar",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 497,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 497,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 497,
                                            "char": 69
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 497,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 497,
                                    "char": 69
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 502,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "joins",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 502,
                                        "char": 44
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 502,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "joins",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 502,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 502,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 502,
                                    "char": 44
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "joins",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 502,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 502,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "sql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": " ",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 503,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 503,
                                                        "char": 32
                                                    },
                                                    "name": "getSqlExpressionJoins",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "definition",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 503,
                                                                    "char": 65
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "joins",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 503,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 503,
                                                                "char": 72
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 503,
                                                            "char": 72
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "escapeChar",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 503,
                                                                "char": 84
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 503,
                                                            "char": 84
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "bindCounts",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 503,
                                                                "char": 96
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 503,
                                                            "char": 96
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 503,
                                                    "char": 97
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 503,
                                                "char": 97
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 503,
                                            "char": 97
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 504,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 509,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "where",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 509,
                                        "char": 44
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 509,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "where",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 509,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 509,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 509,
                                    "char": 44
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "where",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 509,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 509,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "sql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": " ",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 510,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 510,
                                                        "char": 32
                                                    },
                                                    "name": "getSqlExpressionWhere",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "where",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 510,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 510,
                                                            "char": 60
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "escapeChar",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 510,
                                                                "char": 72
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 510,
                                                            "char": 72
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "bindCounts",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 510,
                                                                "char": 84
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 510,
                                                            "char": 84
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 510,
                                                    "char": 85
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 510,
                                                "char": 85
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 510,
                                            "char": 85
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 511,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 516,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "groupBy",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 516,
                                        "char": 46
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 516,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "group",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 516,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 516,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 516,
                                    "char": 46
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "groupBy",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 516,
                                    "char": 56
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 516,
                                "char": 56
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "sql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": " ",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 517,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 517,
                                                        "char": 32
                                                    },
                                                    "name": "getSqlExpressionGroupBy",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "groupBy",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 517,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 517,
                                                            "char": 64
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "escapeChar",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 517,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 517,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 517,
                                                    "char": 77
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 517,
                                                "char": 77
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 517,
                                            "char": 77
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 518,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 523,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "having",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 523,
                                        "char": 46
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 523,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "having",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 523,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 523,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 523,
                                    "char": 46
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "having",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 523,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 523,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "sql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": " ",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 524,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 524,
                                                        "char": 32
                                                    },
                                                    "name": "getSqlExpressionHaving",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "having",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 524,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 524,
                                                            "char": 62
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "escapeChar",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 524,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 524,
                                                            "char": 74
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "bindCounts",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 524,
                                                                "char": 86
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 524,
                                                            "char": 86
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 524,
                                                    "char": 87
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 524,
                                                "char": 87
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 524,
                                            "char": 87
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 525,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 530,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "orderBy",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 530,
                                        "char": 46
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 530,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "order",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 530,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 530,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 530,
                                    "char": 46
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "orderBy",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 530,
                                    "char": 56
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 530,
                                "char": 56
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "sql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": " ",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 531,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 531,
                                                        "char": 32
                                                    },
                                                    "name": "getSqlExpressionOrderBy",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "orderBy",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 531,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 531,
                                                            "char": 64
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "escapeChar",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 531,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 531,
                                                            "char": 76
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "bindCounts",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 531,
                                                                "char": 88
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 531,
                                                            "char": 88
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 531,
                                                    "char": 89
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 531,
                                                "char": 89
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 531,
                                            "char": 89
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 532,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 537,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "limit",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 537,
                                        "char": 44
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 537,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "limit",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 537,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 537,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 537,
                                    "char": 44
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "limit",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 537,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 537,
                                "char": 52
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "sql",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 538,
                                                    "char": 28
                                                },
                                                "name": "getSqlExpressionLimit",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array",
                                                            "left": [
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "sql",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 540,
                                                                        "char": 24
                                                                    },
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "sql",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 540,
                                                                        "char": 31
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 540,
                                                                    "char": 31
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 541,
                                                                        "char": 26
                                                                    },
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "limit",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 542,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 542,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 542,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 542,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 543,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 543,
                                                        "char": 27
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 545,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 545,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 545,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 545,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 546,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 551,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "forUpdate",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 551,
                                        "char": 52
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 551,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "forUpdate",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 551,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 551,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 551,
                                    "char": 52
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "forUpdate",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 551,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 551,
                                "char": 64
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "sql",
                                            "expr": {
                                                "type": "string",
                                                "value": " FOR UPDATE",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 552,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 552,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 553,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 555,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "sql",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 555,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 556,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a SELECT statement\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 459,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 459,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 458,
                    "last-line": 560,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "supportsSavepoints",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 563,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 564,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks whether the platform supports savepoints\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 562,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 562,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 561,
                    "last-line": 568,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "supportsReleaseSavepoints",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 571,
                                    "char": 21
                                },
                                "name": "supportsSavePoints",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 571,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 572,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks whether the platform supports releasing savepoints.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 570,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 570,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 569,
                    "last-line": 576,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getColumnSize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "column",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ColumnInterface",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 577,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 577,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "string",
                                        "value": "(",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 579,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 579,
                                            "char": 27
                                        },
                                        "name": "getSize",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 579,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 579,
                                    "char": 38
                                },
                                "right": {
                                    "type": "string",
                                    "value": ")",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 579,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 579,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 580,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the size of the column enclosed in parentheses\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 578,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 578,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 577,
                    "last-line": 584,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getColumnSizeAndScale",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "column",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ColumnInterface",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 585,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 585,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "(",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 587,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 587,
                                                    "char": 27
                                                },
                                                "name": "getSize",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 587,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 587,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": ",",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 587,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 587,
                                        "char": 42
                                    },
                                    "right": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 587,
                                            "char": 51
                                        },
                                        "name": "getScale",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 587,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 587,
                                    "char": 63
                                },
                                "right": {
                                    "type": "string",
                                    "value": ")",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 587,
                                    "char": 66
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 587,
                                "char": 66
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 588,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the column size and scale enclosed in parentheses\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 586,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 586,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 585,
                    "last-line": 592,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkColumnType",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "column",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ColumnInterface",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 593,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 593,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 595,
                                            "char": 26
                                        },
                                        "name": "getType",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 595,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 595,
                                    "char": 38
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 595,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 595,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 596,
                                            "char": 27
                                        },
                                        "name": "getTypeReference",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 596,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 597,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 599,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 599,
                                    "char": 23
                                },
                                "name": "getType",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 599,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 600,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the column type and if not string it returns the type reference\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 594,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 594,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 593,
                    "last-line": 604,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkColumnTypeSql",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "column",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ColumnInterface",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 605,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 605,
                            "char": 67
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 607,
                                            "char": 26
                                        },
                                        "name": "getType",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 607,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 607,
                                    "char": 38
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 607,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 607,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 608,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 609,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 611,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 611,
                                    "char": 23
                                },
                                "name": "getType",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 611,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 612,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the column type and returns the updated SQL statement\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 606,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 606,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 605,
                    "last-line": 616,
                    "char": 22
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionAll",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 617,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 617,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 617,
                            "char": 93
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "domain",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 619,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 621,
                            "char": 13
                        },
                        {
                            "type": "fetch",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "domain",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 621,
                                    "char": 41
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 621,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "domain",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 621,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 621,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 621,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 623,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 623,
                                    "char": 21
                                },
                                "name": "prepareQualified",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "*",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 623,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 623,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "domain",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 623,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 623,
                                        "char": 48
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "escapeChar",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 623,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 623,
                                        "char": 60
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 623,
                                "char": 61
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 624,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve *\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 618,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 618,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 617,
                    "last-line": 628,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionBinaryOperations",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 629,
                            "char": 80
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 629,
                                "char": 106
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 629,
                            "char": 106
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 629,
                                "char": 125
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 629,
                            "char": 125
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "left",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 631,
                                    "char": 17
                                },
                                {
                                    "variable": "right",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 631,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 633,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "left",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 633,
                                            "char": 26
                                        },
                                        "name": "getSqlExpression",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "expression",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 634,
                                                        "char": 23
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "left",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 634,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 634,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 634,
                                                "char": 29
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 635,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 635,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "bindCounts",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 637,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 637,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 637,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 637,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 639,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "right",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 639,
                                            "char": 26
                                        },
                                        "name": "getSqlExpression",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "expression",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 640,
                                                        "char": 23
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "right",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 640,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 640,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 640,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 641,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 641,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "bindCounts",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 643,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 643,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 643,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 643,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 645,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "variable",
                                                "value": "left",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 645,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": " ",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 645,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 645,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "expression",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 645,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "op",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 645,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 645,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 645,
                                        "char": 42
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": " ",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 645,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 645,
                                    "char": 46
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "right",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 645,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 645,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 646,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve binary operations expressions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 630,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 630,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 629,
                    "last-line": 650,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionCase",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 651,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 651,
                                "char": 94
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 651,
                            "char": 94
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 651,
                                "char": 113
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 651,
                            "char": 113
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "whenClause",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 653,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 654,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 654,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 656,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "sql",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "CASE ",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 656,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 656,
                                                "char": 32
                                            },
                                            "name": "getSqlExpression",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 656,
                                                            "char": 60
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "expr",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 656,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 656,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 656,
                                                    "char": 66
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "escapeChar",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 656,
                                                        "char": 78
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 656,
                                                    "char": 78
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "bindCounts",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 656,
                                                        "char": 90
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 656,
                                                    "char": 90
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 656,
                                            "char": 91
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 656,
                                        "char": 91
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 656,
                                    "char": 91
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 658,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "variable",
                                    "value": "expression",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 658,
                                    "char": 37
                                },
                                "right": {
                                    "type": "string",
                                    "value": "when-clauses",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 658,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 658,
                                "char": 52
                            },
                            "value": "whenClause",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "whenClause",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 659,
                                                "char": 26
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 659,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 659,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "when",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 659,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 659,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "sql",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": " WHEN ",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 660,
                                                                    "char": 34
                                                                },
                                                                "right": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 661,
                                                                        "char": 30
                                                                    },
                                                                    "name": "getSqlExpression",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "array-access",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "whenClause",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                    "line": 661,
                                                                                    "char": 58
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "expr",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                    "line": 661,
                                                                                    "char": 63
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                "line": 661,
                                                                                "char": 64
                                                                            },
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 661,
                                                                            "char": 64
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "escapeChar",
                                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                "line": 661,
                                                                                "char": 76
                                                                            },
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 661,
                                                                            "char": 76
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "bindCounts",
                                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                "line": 661,
                                                                                "char": 88
                                                                            },
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 661,
                                                                            "char": 88
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 661,
                                                                    "char": 90
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 661,
                                                                "char": 90
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": " THEN ",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 662,
                                                                "char": 32
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 662,
                                                            "char": 32
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 663,
                                                                "char": 30
                                                            },
                                                            "name": "getSqlExpression",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "whenClause",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 663,
                                                                            "char": 58
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "then",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 663,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 663,
                                                                        "char": 64
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 663,
                                                                    "char": 64
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "escapeChar",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 663,
                                                                        "char": 76
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 663,
                                                                    "char": 76
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "bindCounts",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 663,
                                                                        "char": 88
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 663,
                                                                    "char": 88
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 663,
                                                            "char": 89
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 663,
                                                        "char": 89
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 663,
                                                    "char": 89
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 664,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "sql",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": " ELSE ",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 665,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 665,
                                                                "char": 41
                                                            },
                                                            "name": "getSqlExpression",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "whenClause",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 665,
                                                                            "char": 69
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "expr",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 665,
                                                                            "char": 74
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 665,
                                                                        "char": 75
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 665,
                                                                    "char": 75
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "escapeChar",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 665,
                                                                        "char": 87
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 665,
                                                                    "char": 87
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "bindCounts",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 665,
                                                                        "char": 99
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 665,
                                                                    "char": 99
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 665,
                                                            "char": 100
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 665,
                                                        "char": 100
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 665,
                                                    "char": 100
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 666,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 667,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 669,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "variable",
                                    "value": "sql",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 669,
                                    "char": 20
                                },
                                "right": {
                                    "type": "string",
                                    "value": " END",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 669,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 669,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 670,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve CASE expressions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 652,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 652,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 651,
                    "last-line": 674,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionCastValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 675,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 675,
                                "char": 99
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 675,
                            "char": 99
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 675,
                                "char": 118
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 675,
                            "char": 118
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "left",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 677,
                                    "char": 17
                                },
                                {
                                    "variable": "right",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 677,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 679,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "left",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 679,
                                            "char": 26
                                        },
                                        "name": "getSqlExpression",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "expression",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 680,
                                                        "char": 23
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "left",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 680,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 680,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 680,
                                                "char": 29
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 681,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 681,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "bindCounts",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 683,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 683,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 683,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 683,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 685,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "right",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 685,
                                            "char": 26
                                        },
                                        "name": "getSqlExpression",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "expression",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 686,
                                                        "char": 23
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "right",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 686,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 686,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 686,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 687,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 687,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "bindCounts",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 689,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 689,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 689,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 689,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 691,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "CAST(",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 691,
                                                "char": 22
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "left",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 691,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 691,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": " AS ",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 691,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 691,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "right",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 691,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 691,
                                    "char": 44
                                },
                                "right": {
                                    "type": "string",
                                    "value": ")",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 691,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 691,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 692,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve CAST of values\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 676,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 676,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 675,
                    "last-line": 696,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionConvertValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 697,
                            "char": 76
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 697,
                                "char": 102
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 697,
                            "char": 102
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 697,
                                "char": 121
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 697,
                            "char": 121
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "left",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 699,
                                    "char": 17
                                },
                                {
                                    "variable": "right",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 699,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 701,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "left",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 701,
                                            "char": 26
                                        },
                                        "name": "getSqlExpression",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "expression",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 702,
                                                        "char": 23
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "left",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 702,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 702,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 702,
                                                "char": 29
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 703,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 703,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "bindCounts",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 705,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 705,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 705,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 705,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 707,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "right",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 707,
                                            "char": 26
                                        },
                                        "name": "getSqlExpression",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "expression",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 708,
                                                        "char": 23
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "right",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 708,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 708,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 708,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 709,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 709,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "bindCounts",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 711,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 711,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 711,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 711,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 713,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "CONVERT(",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 713,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "left",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 713,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 713,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": " USING ",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 713,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 713,
                                        "char": 42
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "right",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 713,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 713,
                                    "char": 50
                                },
                                "right": {
                                    "type": "string",
                                    "value": ")",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 713,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 713,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 714,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve CONVERT of values encodings\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 698,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 698,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 697,
                    "last-line": 718,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionFrom",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 719,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 719,
                                "char": 91
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 719,
                            "char": 91
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "table",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 721,
                                    "char": 18
                                },
                                {
                                    "variable": "tables",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 721,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 723,
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
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 723,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 723,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 723,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 723,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "tables",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 724,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 724,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 726,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 726,
                                        "char": 37
                                    },
                                    "value": "table",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "tables",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 727,
                                                            "char": 37
                                                        },
                                                        "name": "getSqlTable",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "table",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 727,
                                                                    "char": 55
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 727,
                                                                "char": 55
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "escapeChar",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 727,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 727,
                                                                "char": 67
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 727,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 727,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 728,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 730,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "tables",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "join",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": ", ",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 730,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 730,
                                                        "char": 33
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "tables",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 730,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 730,
                                                        "char": 41
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 730,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 730,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 731,
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
                                            "variable": "tables",
                                            "expr": {
                                                "type": "variable",
                                                "value": "expression",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 732,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 732,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 733,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 735,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "FROM ",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 735,
                                    "char": 22
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "tables",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 735,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 735,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 736,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve a FROM clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 720,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 720,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 719,
                    "last-line": 740,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionFunctionCall",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 741,
                            "char": 76
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 741,
                                "char": 102
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 741,
                            "char": 102
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 741,
                            "char": 114
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 743,
                                    "char": 17
                                },
                                {
                                    "variable": "customFunction",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 743,
                                    "char": 33
                                },
                                {
                                    "variable": "arguments",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 743,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 745,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "expression",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 745,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 745,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 745,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 745,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 747,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "customFunction",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 747,
                                    "char": 62
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 747,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "customFunctions",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 747,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 747,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 747,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 747,
                                    "char": 62
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 747,
                                "char": 62
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "customFunction",
                                        "call-type": 2,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 748,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 748,
                                                "char": 41
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 748,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 748,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 748,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 748,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 748,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 749,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 751,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "arguments",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 751,
                                        "char": 52
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "expression",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 751,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "arguments",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 751,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 751,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 751,
                                    "char": 52
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "arguments",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 751,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 751,
                                        "char": 72
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 751,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 751,
                                    "char": 80
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 751,
                                "char": 80
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "arguments",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 753,
                                                    "char": 34
                                                },
                                                "name": "getSqlExpression",
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
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 755,
                                                                        "char": 25
                                                                    },
                                                                    "value": {
                                                                        "type": "string",
                                                                        "value": "list",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 755,
                                                                        "char": 38
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 755,
                                                                    "char": 38
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "parentheses",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 756,
                                                                        "char": 32
                                                                    },
                                                                    "value": {
                                                                        "type": "bool",
                                                                        "value": "false",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 756,
                                                                        "char": 39
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 756,
                                                                    "char": 39
                                                                },
                                                                {
                                                                    "key": {
                                                                        "type": "string",
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 757,
                                                                        "char": 26
                                                                    },
                                                                    "value": {
                                                                        "type": "variable",
                                                                        "value": "arguments",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 758,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 758,
                                                                    "char": 17
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 758,
                                                            "char": 18
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 758,
                                                        "char": 18
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 759,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 759,
                                                        "char": 27
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 761,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 761,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 761,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 761,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 763,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 763,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "distinct",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 763,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 763,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 763,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "expression",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 763,
                                                "char": 56
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "distinct",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 763,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 763,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 763,
                                        "char": 67
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 764,
                                                            "char": 29
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "(DISTINCT ",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 764,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 764,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "arguments",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 764,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 764,
                                                    "char": 54
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": ")",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 764,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 764,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 765,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 767,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 767,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "(",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 767,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 767,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "arguments",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 767,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 767,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": ")",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 767,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 767,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 768,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 770,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 770,
                                    "char": 21
                                },
                                "right": {
                                    "type": "string",
                                    "value": "()",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 770,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 770,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 771,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve function calls\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 742,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 742,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 741,
                    "last-line": 775,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionGroupBy",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 776,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 776,
                                "char": 94
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 776,
                            "char": 94
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 776,
                                "char": 113
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 776,
                            "char": 113
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "field",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 778,
                                    "char": 18
                                },
                                {
                                    "variable": "fields",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 778,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 780,
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
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 780,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 780,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 780,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 780,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "fields",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 781,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 781,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 783,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 783,
                                        "char": 37
                                    },
                                    "value": "field",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "not-equals",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 784,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 784,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 784,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 784,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 784,
                                                "char": 51
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
                                                                    "value": "Invalid SQL-GROUP-BY expression",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 785,
                                                                    "char": 72
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 785,
                                                                "char": 72
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 785,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 786,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 788,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "fields",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 788,
                                                            "char": 37
                                                        },
                                                        "name": "getSqlExpression",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "field",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 789,
                                                                    "char": 26
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 789,
                                                                "char": 26
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "escapeChar",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 790,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 790,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "bindCounts",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 792,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 792,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 792,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 792,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 793,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 795,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "fields",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "join",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": ", ",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 795,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 795,
                                                        "char": 33
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "fields",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 795,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 795,
                                                        "char": 41
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 795,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 795,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 796,
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
                                            "variable": "fields",
                                            "expr": {
                                                "type": "variable",
                                                "value": "expression",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 797,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 797,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 798,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 800,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "GROUP BY ",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 800,
                                    "char": 26
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "fields",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 800,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 800,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 801,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve a GROUP BY clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 777,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 777,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 776,
                    "last-line": 805,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionHaving",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 806,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 806,
                                "char": 96
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 806,
                            "char": 96
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 806,
                                "char": 115
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 806,
                            "char": 115
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "HAVING ",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 808,
                                    "char": 24
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 808,
                                        "char": 31
                                    },
                                    "name": "getSqlExpression",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "expression",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 808,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 808,
                                            "char": 59
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "escapeChar",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 808,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 808,
                                            "char": 71
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "bindCounts",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 808,
                                                "char": 83
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 808,
                                            "char": 83
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 808,
                                    "char": 84
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 808,
                                "char": 84
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 809,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve a HAVING clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 807,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 807,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 806,
                    "last-line": 813,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionJoins",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 814,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 814,
                                "char": 92
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 814,
                            "char": 92
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 814,
                                "char": 111
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 814,
                            "char": 111
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "condition",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 816,
                                    "char": 22
                                },
                                {
                                    "variable": "join",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 816,
                                    "char": 28
                                },
                                {
                                    "variable": "joinCondition",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 816,
                                    "char": 43
                                },
                                {
                                    "variable": "joinTable",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 816,
                                    "char": 54
                                },
                                {
                                    "variable": "joinType",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 816,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 816,
                                    "char": 67
                                },
                                {
                                    "variable": "joinConditionsArray",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 817,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 818,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 818,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 818,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 820,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "expression",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 820,
                                "char": 32
                            },
                            "value": "join",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "joinConditionsArray",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 824,
                                                "char": 61
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "join",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 824,
                                                    "char": 47
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "conditions",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 824,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 824,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 824,
                                            "char": 61
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "joinConditionsArray",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 824,
                                                    "char": 90
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 824,
                                                "char": 90
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 824,
                                            "char": 90
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 824,
                                        "char": 90
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "isset",
                                                    "left": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "joinConditionsArray",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 825,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 825,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 825,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 825,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 825,
                                                "char": 50
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "joinCondition",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 826,
                                                                    "char": 46
                                                                },
                                                                "name": "getSqlExpression",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "joinConditionsArray",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 827,
                                                                            "char": 44
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 827,
                                                                        "char": 44
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "escapeChar",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 828,
                                                                            "char": 35
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 828,
                                                                        "char": 35
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "bindCounts",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 830,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 830,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 830,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 830,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 831,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "joinCondition",
                                                            "expr": {
                                                                "type": "empty-array",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 832,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 832,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 834,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "joinConditionsArray",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 834,
                                                        "char": 58
                                                    },
                                                    "value": "condition",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable-append",
                                                                    "operator": "assign",
                                                                    "variable": "joinCondition",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 835,
                                                                            "char": 52
                                                                        },
                                                                        "name": "getSqlExpression",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "condition",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                    "line": 836,
                                                                                    "char": 38
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                "line": 836,
                                                                                "char": 38
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "escapeChar",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                    "line": 837,
                                                                                    "char": 39
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                "line": 837,
                                                                                "char": 39
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "bindCounts",
                                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                    "line": 839,
                                                                                    "char": 25
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                                "line": 839,
                                                                                "char": 25
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 839,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 839,
                                                                    "char": 26
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 840,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 842,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "joinCondition",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "join",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": " AND ",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 842,
                                                                            "char": 51
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 842,
                                                                        "char": 51
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "joinCondition",
                                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                            "line": 842,
                                                                            "char": 66
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 842,
                                                                        "char": 66
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 842,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 842,
                                                            "char": 67
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 843,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 844,
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
                                                    "variable": "joinCondition",
                                                    "expr": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 845,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 845,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 846,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 848,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "joinType",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 848,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "join",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 848,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 848,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 848,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 848,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "joinType",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 848,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 848,
                                        "char": 55
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "joinType",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": " ",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 849,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 849,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 850,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 852,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "joinTable",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 852,
                                                    "char": 34
                                                },
                                                "name": "getSqlTable",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "join",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 852,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "source",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 852,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 852,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 852,
                                                        "char": 59
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 852,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 852,
                                                        "char": 71
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 852,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 852,
                                            "char": 72
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 854,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "sql",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": " ",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 854,
                                                                    "char": 25
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "joinType",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 854,
                                                                    "char": 36
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 854,
                                                                "char": 36
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "JOIN ",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 854,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 854,
                                                            "char": 44
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "joinTable",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 854,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 854,
                                                        "char": 56
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " ON ",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 854,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 854,
                                                    "char": 63
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "joinCondition",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 854,
                                                    "char": 78
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 854,
                                                "char": 78
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 854,
                                            "char": 78
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 855,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 857,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "sql",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 857,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 858,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve a JOINs clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 815,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 815,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 814,
                    "last-line": 862,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionLimit",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 863,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 863,
                                "char": 92
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 863,
                            "char": 92
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 863,
                                "char": 111
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 863,
                            "char": 111
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "sql",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 865,
                                        "char": 19
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 865,
                                    "char": 19
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 865,
                                    "char": 26
                                },
                                {
                                    "variable": "limit",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 865,
                                    "char": 33
                                },
                                {
                                    "variable": "offset",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 865,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 865,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 867,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "expression",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 867,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 867,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 867,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 867,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 869,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 869,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "sql",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 869,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 869,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 869,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "sql",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 870,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "sql",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 870,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 870,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 870,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 871,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 873,
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
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 873,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 873,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 873,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 873,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 874,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "number",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 874,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 874,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 874,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 874,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 874,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "limit",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 875,
                                                            "char": 34
                                                        },
                                                        "name": "getSqlExpression",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 876,
                                                                        "char": 26
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "number",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 876,
                                                                        "char": 33
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 876,
                                                                    "char": 34
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 876,
                                                                "char": 34
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "escapeChar",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 877,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 877,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "bindCounts",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 879,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 879,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 879,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 879,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 880,
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
                                                    "variable": "limit",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 881,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "number",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 881,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 881,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 881,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 882,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 887,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "offset",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 887,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 887,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "offset",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 887,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 887,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 887,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "offset",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 887,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 887,
                                                "char": 62
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 887,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 887,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 887,
                                        "char": 70
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "offset",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 888,
                                                            "char": 35
                                                        },
                                                        "name": "getSqlExpression",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "offset",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 889,
                                                                    "char": 27
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 889,
                                                                "char": 27
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "escapeChar",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 890,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 890,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "bindCounts",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 892,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 892,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 892,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 892,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 893,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 895,
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
                                            "variable": "limit",
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 896,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 896,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 897,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 899,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 899,
                                    "char": 21
                                },
                                "name": "limit",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "sql",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 899,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 899,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "limit",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 899,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 899,
                                                    "char": 39
                                                },
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "offset",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 899,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 899,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 899,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 899,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 899,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 900,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve a LIMIT clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 864,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 864,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 863,
                    "last-line": 904,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionList",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 905,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 905,
                                "char": 94
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 905,
                            "char": 94
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 905,
                                "char": 113
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 905,
                            "char": 113
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "item",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 907,
                                    "char": 17
                                },
                                {
                                    "variable": "values",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 907,
                                    "char": 25
                                },
                                {
                                    "variable": "separator",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 907,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 908,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "items",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 908,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 910,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "items",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 910,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 910,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 911,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "separator",
                                    "expr": {
                                        "type": "string",
                                        "value": ", ",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 911,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 911,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 913,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 913,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "separator",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 913,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 913,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 913,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "separator",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 914,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "separator",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 914,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 914,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 914,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 915,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 917,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "or",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "values",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 917,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 917,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 917,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 917,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 917,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "values",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 917,
                                                "char": 75
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 917,
                                                    "char": 68
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 917,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 917,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 917,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 917,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 917,
                                    "char": 78
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "values",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 917,
                                            "char": 95
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 917,
                                        "char": 95
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 917,
                                        "char": 103
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 917,
                                    "char": 103
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 917,
                                "char": 103
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "values",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 919,
                                        "char": 32
                                    },
                                    "value": "item",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "items",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 920,
                                                            "char": 36
                                                        },
                                                        "name": "getSqlExpression",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "item",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 920,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 920,
                                                                "char": 58
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "escapeChar",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 920,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 920,
                                                                "char": 70
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "bindCounts",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 920,
                                                                    "char": 82
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 920,
                                                                "char": 82
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 920,
                                                        "char": 83
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 920,
                                                    "char": 83
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 921,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 923,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 923,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "parentheses",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 923,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 923,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 923,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "identical",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 923,
                                                    "char": 59
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "parentheses",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 923,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 923,
                                                "char": 75
                                            },
                                            "right": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 923,
                                                "char": 83
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 923,
                                            "char": 83
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 923,
                                        "char": 83
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "join",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "separator",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 924,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 924,
                                                        "char": 38
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "items",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 924,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 924,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 924,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 925,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 927,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": "(",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 927,
                                                "char": 22
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "join",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "separator",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 927,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 927,
                                                        "char": 38
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "items",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 927,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 927,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 927,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 927,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": ")",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 927,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 927,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 928,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 930,
                            "char": 13
                        },
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
                                            "value": "Invalid SQL-list expression",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 930,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 930,
                                        "char": 56
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 930,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 931,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve Lists\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 906,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 906,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 905,
                    "last-line": 935,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionObject",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 936,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 936,
                                "char": 96
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 936,
                            "char": 96
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 936,
                                "char": 115
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 936,
                            "char": 115
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "domain",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 938,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 938,
                                    "char": 26
                                },
                                {
                                    "variable": "objectExpression",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 938,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 940,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "objectExpression",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 941,
                                                    "char": 17
                                                },
                                                "value": {
                                                    "type": "string",
                                                    "value": "all",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 942,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 942,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 942,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 942,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 944,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "or",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "domain",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 944,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 944,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "column",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 944,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 944,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 944,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "domain",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 944,
                                                "char": 81
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 944,
                                                    "char": 73
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "domain",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 944,
                                                    "char": 80
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 944,
                                                "char": 81
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 944,
                                            "char": 81
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 944,
                                        "char": 81
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 944,
                                    "char": 84
                                },
                                "right": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "domain",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 944,
                                        "char": 94
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 944,
                                        "char": 97
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 944,
                                    "char": 97
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 944,
                                "char": 97
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "objectExpression",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "domain",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 945,
                                                    "char": 40
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "domain",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 945,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 945,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 946,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 948,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 948,
                                    "char": 21
                                },
                                "name": "getSqlExpression",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "objectExpression",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 948,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 948,
                                        "char": 55
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "escapeChar",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 948,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 948,
                                        "char": 67
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "bindCounts",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 948,
                                            "char": 79
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 948,
                                        "char": 79
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 948,
                                "char": 80
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 949,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve object expressions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 937,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 937,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 936,
                    "last-line": 953,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionOrderBy",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 954,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 954,
                                "char": 94
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 954,
                            "char": 94
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 954,
                                "char": 113
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 954,
                            "char": 113
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "field",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 956,
                                    "char": 18
                                },
                                {
                                    "variable": "fields",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 956,
                                    "char": 26
                                },
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 956,
                                    "char": 32
                                },
                                {
                                    "variable": "fieldSql",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 956,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 956,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 958,
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
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 958,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 958,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 958,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 958,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "fields",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 959,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 959,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 961,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 961,
                                        "char": 37
                                    },
                                    "value": "field",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "not-equals",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 963,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 963,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 963,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 963,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 963,
                                                "char": 51
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
                                                                    "value": "Invalid SQL-ORDER-BY expression",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 964,
                                                                    "char": 72
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 964,
                                                                "char": 72
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 964,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 965,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 967,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "fieldSql",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 967,
                                                            "char": 37
                                                        },
                                                        "name": "getSqlExpression",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "field",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 968,
                                                                        "char": 26
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "0",
                                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                        "line": 968,
                                                                        "char": 28
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 968,
                                                                    "char": 29
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 968,
                                                                "char": 29
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "escapeChar",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 969,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 969,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "bindCounts",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 971,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 971,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 971,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 971,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 976,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "fetch",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "type",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 976,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 976,
                                                            "char": 37
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 976,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 976,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 976,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "not-equals",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "type",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 976,
                                                        "char": 50
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 976,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 976,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 976,
                                                "char": 53
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "fieldSql",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": " ",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 977,
                                                                    "char": 38
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "type",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 977,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 977,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 977,
                                                            "char": 44
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 978,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 980,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "fields",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "fieldSql",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 980,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 980,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 981,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 983,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "fields",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "join",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": ", ",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 983,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 983,
                                                        "char": 33
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "fields",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 983,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 983,
                                                        "char": 41
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 983,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 983,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 984,
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
                                            "variable": "fields",
                                            "expr": {
                                                "type": "variable",
                                                "value": "expression",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 985,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 985,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 986,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 988,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "ORDER BY ",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 988,
                                    "char": 26
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "fields",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 988,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 988,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 989,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve an ORDER BY clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 955,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 955,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 954,
                    "last-line": 993,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionQualified",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 994,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 994,
                                "char": 99
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 994,
                            "char": 99
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "column",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 996,
                                    "char": 19
                                },
                                {
                                    "variable": "domain",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 996,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 998,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "column",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "expression",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 998,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 998,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 998,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 998,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1003,
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
                                        "value": "domain",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1003,
                                        "char": 46
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "expression",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1003,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "domain",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1003,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1003,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1003,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1003,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "domain",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1004,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1004,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1005,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1007,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1007,
                                    "char": 21
                                },
                                "name": "prepareQualified",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1007,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1007,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "domain",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1007,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1007,
                                        "char": 53
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "escapeChar",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1007,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1007,
                                        "char": 65
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1007,
                                "char": 66
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1008,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve qualified expressions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 995,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 995,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 994,
                    "last-line": 1012,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionScalar",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1013,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1013,
                                "char": 96
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1013,
                            "char": 96
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1013,
                                "char": 115
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1013,
                            "char": 115
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1015,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1017,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1017,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "column",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1017,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1017,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1017,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1018,
                                            "char": 25
                                        },
                                        "name": "getSqlColumn",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "expression",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1018,
                                                        "char": 49
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "column",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1018,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1018,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1018,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1018,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1019,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1021,
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
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1021,
                                            "char": 53
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "expression",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1021,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1021,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1021,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1021,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1021,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1021,
                                "char": 53
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
                                                    "value": "Invalid SQL expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1022,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1022,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1022,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1023,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1025,
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
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1025,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1025,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1025,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1025,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1026,
                                            "char": 25
                                        },
                                        "name": "getSqlExpression",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1026,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1026,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1026,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1026,
                                                "char": 60
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "bindCounts",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1026,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1026,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1026,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1027,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1029,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1029,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1030,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve Column expressions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1014,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 1014,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 1013,
                    "last-line": 1034,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionUnaryOperations",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1035,
                            "char": 79
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1035,
                                "char": 105
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1035,
                            "char": 105
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1035,
                                "char": 124
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1035,
                            "char": 124
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "left",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1037,
                                    "char": 17
                                },
                                {
                                    "variable": "right",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1037,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1042,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "left",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1042,
                                    "char": 41
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1042,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "left",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1042,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1042,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1042,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1043,
                                                    "char": 25
                                                },
                                                "name": "getSqlExpression",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "left",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 1043,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1043,
                                                        "char": 47
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 1043,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1043,
                                                        "char": 59
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 1043,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1043,
                                                        "char": 71
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1043,
                                                "char": 73
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": " ",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1043,
                                                "char": 77
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1043,
                                            "char": 77
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "expression",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1043,
                                                "char": 89
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "op",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1043,
                                                "char": 92
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1043,
                                            "char": 93
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1043,
                                        "char": 93
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1044,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1049,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "right",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1049,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1049,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "right",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1049,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1049,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1049,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "expression",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1050,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "op",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1050,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1050,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": " ",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1050,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1050,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1050,
                                                "char": 46
                                            },
                                            "name": "getSqlExpression",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "right",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1050,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1050,
                                                    "char": 69
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "escapeChar",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1050,
                                                        "char": 81
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1050,
                                                    "char": 81
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "bindCounts",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1050,
                                                        "char": 93
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1050,
                                                    "char": 93
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1050,
                                            "char": 94
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1050,
                                        "char": 94
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1051,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1053,
                            "char": 13
                        },
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
                                            "value": "Invalid SQL-unary expression",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1053,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1053,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1053,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1054,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve unary operations expressions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1036,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 1036,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 1035,
                    "last-line": 1058,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSqlExpressionWhere",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "expression",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1059,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1059,
                                "char": 92
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1059,
                            "char": 92
                        },
                        {
                            "type": "parameter",
                            "name": "bindCounts",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1059,
                                "char": 111
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1059,
                            "char": 111
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "whereSql",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1061,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1063,
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
                                        "value": "expression",
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1063,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1063,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1063,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1063,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "whereSql",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1064,
                                                    "char": 33
                                                },
                                                "name": "getSqlExpression",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "expression",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 1064,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1064,
                                                        "char": 61
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "escapeChar",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 1064,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1064,
                                                        "char": 73
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCounts",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 1064,
                                                            "char": 85
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1064,
                                                        "char": 85
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1064,
                                                "char": 86
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1064,
                                            "char": 86
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1065,
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
                                            "variable": "whereSql",
                                            "expr": {
                                                "type": "variable",
                                                "value": "expression",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1066,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1066,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1067,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1069,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "string",
                                    "value": "WHERE ",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1069,
                                    "char": 23
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "whereSql",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1069,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1069,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1070,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve a WHERE clause\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1060,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 1060,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 1059,
                    "last-line": 1074,
                    "char": 28
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "prepareColumnAlias",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "qualified",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1075,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "alias",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1075,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1075,
                            "char": 81
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1075,
                                "char": 107
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1075,
                            "char": 107
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "alias",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1077,
                                    "char": 19
                                },
                                "right": {
                                    "type": "string",
                                    "value": "",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1077,
                                    "char": 22
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1077,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "variable",
                                                "value": "qualified",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1078,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": " AS ",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1078,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1078,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1078,
                                                "char": 44
                                            },
                                            "name": "escape",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "alias",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1078,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1078,
                                                    "char": 57
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "escapeChar",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1078,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1078,
                                                    "char": 69
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1078,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1078,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1079,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1081,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "qualified",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1081,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1082,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prepares column for this RDBMS\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1076,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 1076,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 1075,
                    "last-line": 1086,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "prepareTable",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "table",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1087,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "schema",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1087,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1087,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "alias",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1087,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1087,
                            "char": 93
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1087,
                                "char": 119
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1087,
                            "char": 119
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "table",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1089,
                                            "char": 26
                                        },
                                        "name": "escape",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "table",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1089,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1089,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1089,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1089,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1089,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1089,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1094,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "schema",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1094,
                                    "char": 20
                                },
                                "right": {
                                    "type": "string",
                                    "value": "",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1094,
                                    "char": 23
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1094,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "table",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 1095,
                                                            "char": 30
                                                        },
                                                        "name": "escapeSchema",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "schema",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 1095,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 1095,
                                                                "char": 50
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "escapeChar",
                                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                    "line": 1095,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 1095,
                                                                "char": 62
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1095,
                                                        "char": 64
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": ".",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1095,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1095,
                                                    "char": 68
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "table",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1095,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1095,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1095,
                                            "char": 75
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1096,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1101,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "alias",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1101,
                                    "char": 19
                                },
                                "right": {
                                    "type": "string",
                                    "value": "",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1101,
                                    "char": 22
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1101,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "table",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "table",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1102,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " AS ",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1102,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1102,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1102,
                                                        "char": 45
                                                    },
                                                    "name": "escape",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "alias",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 1102,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 1102,
                                                            "char": 58
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "escapeChar",
                                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                                "line": 1102,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 1102,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1102,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1102,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1102,
                                            "char": 71
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1103,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1105,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "table",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1105,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1106,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prepares table for this RDBMS\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1088,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 1088,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 1087,
                    "last-line": 1110,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "prepareQualified",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "column",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1111,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "domain",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1111,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1111,
                            "char": 77
                        },
                        {
                            "type": "parameter",
                            "name": "escapeChar",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1111,
                                "char": 103
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1111,
                            "char": 103
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "domain",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1113,
                                    "char": 20
                                },
                                "right": {
                                    "type": "string",
                                    "value": "",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1113,
                                    "char": 23
                                },
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1113,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1114,
                                            "char": 25
                                        },
                                        "name": "escape",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "domain",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 1114,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": ".",
                                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                            "line": 1114,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1114,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "column",
                                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                        "line": 1114,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1114,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1114,
                                                "char": 52
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "escapeChar",
                                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                    "line": 1114,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                                "line": 1114,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1114,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1115,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1117,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                    "line": 1117,
                                    "char": 21
                                },
                                "name": "escape",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "column",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1117,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1117,
                                        "char": 35
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "escapeChar",
                                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                            "line": 1117,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                        "line": 1117,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1117,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Db\/Dialect.zep",
                            "line": 1118,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prepares qualified for this RDBMS\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Dialect.zep",
                                "line": 1112,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Dialect.zep",
                        "line": 1112,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Dialect.zep",
                    "line": 1111,
                    "last-line": 1119,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Db\/Dialect.zep",
            "line": 17,
            "char": 14
        },
        "file": "\/app\/phalcon\/Db\/Dialect.zep",
        "line": 17,
        "char": 14
    }
]