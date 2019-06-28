[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Tag\/Select.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Tag",
        "file": "\/app\/phalcon\/Tag\/Select.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Tag\\Exception",
                "file": "\/app\/phalcon\/Tag\/Select.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Tag\/Select.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Tag",
                "alias": "BaseTag",
                "file": "\/app\/phalcon\/Tag\/Select.zep",
                "line": 14,
                "char": 27
            }
        ],
        "file": "\/app\/phalcon\/Tag\/Select.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\EscaperInterface",
                "file": "\/app\/phalcon\/Tag\/Select.zep",
                "line": 15,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Tag\/Select.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\ResulsetInterface",
                "file": "\/app\/phalcon\/Tag\/Select.zep",
                "line": 16,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Tag\/Select.zep",
        "line": 23,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Tag\\Select\n *\n * Generates a SELECT html tag using a static array of values or a\n * Phalcon\\Mvc\\Model resultset\n *",
        "file": "\/app\/phalcon\/Tag\/Select.zep",
        "line": 24,
        "char": 8
    },
    {
        "type": "class",
        "name": "Select",
        "abstract": 1,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "selectField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 32,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 32,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 32,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 34,
                                    "char": 19
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 34,
                                    "char": 25
                                },
                                {
                                    "variable": "id",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 34,
                                    "char": 29
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 34,
                                    "char": 36
                                },
                                {
                                    "variable": "useEmpty",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 34,
                                    "char": 46
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 34,
                                    "char": 52
                                },
                                {
                                    "variable": "emptyValue",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 34,
                                    "char": 64
                                },
                                {
                                    "variable": "emptyText",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 34,
                                    "char": 75
                                },
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 35,
                                    "char": 20
                                },
                                {
                                    "variable": "using",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 35,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 37,
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
                                        "value": "parameters",
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 37,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 37,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 37,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 37,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 38,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 38,
                                                        "char": 37
                                                    },
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "data",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 38,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 38,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 38,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 38,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 39,
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
                                            "variable": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameters",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 40,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 40,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 41,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 43,
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
                                        "value": "id",
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 43,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 43,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 43,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 43,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 43,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 43,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 44,
                                                    "char": 25
                                                }
                                            ],
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 44,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "id",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 44,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 44,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 44,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 45,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 50,
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
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 50,
                                                "char": 22
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 50,
                                            "char": 22
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "[",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 50,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 50,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 50,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 50,
                                "char": 27
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
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 51,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "id",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 51,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 51,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 51,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 51,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "id",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 52,
                                                            "char": 30
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 52,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 52,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 53,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 54,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 56,
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
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 56,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 56,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 56,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 56,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 56,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 56,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 57,
                                                    "char": 28
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 57,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 57,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 58,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 59,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 59,
                                        "char": 22
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 60,
                                                            "char": 32
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 60,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 60,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 61,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 62,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 64,
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
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 64,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 64,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 64,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 64,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 64,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 64,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "value",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "BaseTag",
                                                "dynamic": 0,
                                                "name": "getValue",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "id",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 65,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 65,
                                                        "char": 45
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 65,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 65,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 65,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 65,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 66,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 67,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 67,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 67,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 68,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 70,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "useEmpty",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 70,
                                    "char": 45
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 70,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "useEmpty",
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 70,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 70,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 70,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "emptyValue",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 71,
                                                "char": 54
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 71,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "emptyValue",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 71,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 71,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 71,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 71,
                                        "char": 54
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "emptyValue",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "",
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 72,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 72,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 73,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 74,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "emptyValue",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 74,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 74,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 75,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 77,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "emptyText",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 77,
                                                "char": 52
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 77,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "emptyText",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 77,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 77,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 77,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 77,
                                        "char": 52
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "emptyText",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "Choose...",
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 78,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 78,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 79,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 80,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "emptyText",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 80,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 80,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 81,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 83,
                                    "char": 17
                                },
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 83,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "useEmpty",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 83,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 83,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 84,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 86,
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
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 86,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 86,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 86,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 86,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 86,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 86,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "options",
                                            "expr": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 87,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 87,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 88,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 90,
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
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 90,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 90,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 90,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 90,
                                "char": 37
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
                                                    "value": "using",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 94,
                                                    "char": 53
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "params",
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 94,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "using",
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 94,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 94,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 94,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 94,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 94,
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
                                                            "value": "The 'using' parameter is required",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 95,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 95,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 95,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 96,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 98,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "and",
                                                "left": {
                                                    "type": "not-equals",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "using",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 98,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 98,
                                                        "char": 40
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 98,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 98,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "not-equals",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "using",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 98,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 98,
                                                        "char": 65
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 98,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 98,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 98,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 98,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 98,
                                        "char": 75
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
                                                            "value": "The 'using' parameter should be an array",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 101,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 101,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 101,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 102,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 103,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 105,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "variable",
                                    "value": "params",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 105,
                                    "char": 21
                                },
                                "right": {
                                    "type": "string",
                                    "value": "using",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 105,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 105,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 107,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "BaseTag",
                                                "dynamic": 0,
                                                "name": "renderAttributes",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "<select",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 107,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 107,
                                                        "char": 53
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 107,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 107,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 107,
                                                "char": 63
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": ">",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 107,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 107,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "constant",
                                            "value": "PHP_EOL",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 107,
                                            "char": 76
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 107,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 107,
                                    "char": 76
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 109,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "useEmpty",
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 109,
                                "char": 21
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "code",
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
                                                                    "value": "\\t<option value=\\\"",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 113,
                                                                    "char": 43
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "emptyValue",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 113,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 113,
                                                                "char": 56
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "\\\">",
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 113,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 113,
                                                            "char": 62
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "emptyText",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 113,
                                                            "char": 74
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 113,
                                                        "char": 74
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "<\/option>",
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 113,
                                                        "char": 86
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 113,
                                                    "char": 86
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 113,
                                                    "char": 95
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 113,
                                                "char": 95
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 113,
                                            "char": 95
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 114,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 116,
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
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 116,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 116,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 116,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 116,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "code",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "self",
                                                "dynamic": 0,
                                                "name": "optionsFromResultset",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 121,
                                                            "char": 24
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 121,
                                                        "char": 24
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "using",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 122,
                                                            "char": 22
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 122,
                                                        "char": 22
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 123,
                                                            "char": 22
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 123,
                                                        "char": 22
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "<\/option>",
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 124,
                                                                "char": 27
                                                            },
                                                            "right": {
                                                                "type": "constant",
                                                                "value": "PHP_EOL",
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 125,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 125,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 125,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 125,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 125,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 126,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 127,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 127,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 127,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 127,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "code",
                                                    "expr": {
                                                        "type": "scall",
                                                        "dynamic-class": 0,
                                                        "class": "self",
                                                        "dynamic": 0,
                                                        "name": "optionsFromArray",
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "options",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 132,
                                                                    "char": 28
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 132,
                                                                "char": 28
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 133,
                                                                    "char": 26
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 133,
                                                                "char": 26
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": "<\/option>",
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 134,
                                                                        "char": 31
                                                                    },
                                                                    "right": {
                                                                        "type": "constant",
                                                                        "value": "PHP_EOL",
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 135,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 135,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 135,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 135,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 135,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 136,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 137,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 139,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "string",
                                        "value": "<\/select>",
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 139,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 139,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 141,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 141,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 142,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a SELECT tag\n     *\n     * @param array parameters\n     * @param array data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 33,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                        "line": 33,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                    "line": 32,
                    "last-line": 146,
                    "char": 26
                },
                {
                    "visibility": [
                        "private",
                        "static"
                    ],
                    "type": "method",
                    "name": "optionsFromArray",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 147,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 147,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "closeOption",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 147,
                            "char": 87
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "strValue",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 149,
                                    "char": 21
                                },
                                {
                                    "variable": "strOptionValue",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 149,
                                    "char": 37
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 149,
                                    "char": 43
                                },
                                {
                                    "variable": "optionValue",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 149,
                                    "char": 56
                                },
                                {
                                    "variable": "optionText",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 149,
                                    "char": 68
                                },
                                {
                                    "variable": "escaped",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 149,
                                    "char": 77
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 151,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 151,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 151,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 153,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 153,
                                "char": 45
                            },
                            "key": "optionValue",
                            "value": "optionText",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "escaped",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "htmlspecialchars",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "optionValue",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 154,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 154,
                                                        "char": 55
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 154,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 154,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 156,
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
                                                "value": "optionText",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 156,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 156,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 156,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 156,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "code",
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
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "\\t<optgroup label=\\\"",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 157,
                                                                                "char": 49
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "escaped",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 157,
                                                                                "char": 59
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 157,
                                                                            "char": 59
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "\\\">",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 157,
                                                                            "char": 65
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 157,
                                                                        "char": 65
                                                                    },
                                                                    "right": {
                                                                        "type": "constant",
                                                                        "value": "PHP_EOL",
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 157,
                                                                        "char": 75
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 157,
                                                                    "char": 75
                                                                },
                                                                "right": {
                                                                    "type": "scall",
                                                                    "dynamic-class": 0,
                                                                    "class": "self",
                                                                    "dynamic": 0,
                                                                    "name": "optionsFromArray",
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "optionText",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 157,
                                                                                "char": 110
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 157,
                                                                            "char": 110
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "value",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 157,
                                                                                "char": 117
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 157,
                                                                            "char": 117
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "closeOption",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 157,
                                                                                "char": 130
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 157,
                                                                            "char": 130
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 157,
                                                                    "char": 132
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 157,
                                                                "char": 132
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "\\t<\/optgroup>",
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 157,
                                                                "char": 148
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 157,
                                                            "char": 148
                                                        },
                                                        "right": {
                                                            "type": "constant",
                                                            "value": "PHP_EOL",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 157,
                                                            "char": 157
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 157,
                                                        "char": 157
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 157,
                                                    "char": 157
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 159,
                                            "char": 24
                                        },
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 160,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 162,
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
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 162,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 162,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 162,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 162,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "in_array",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "optionValue",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 163,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 163,
                                                        "char": 40
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 163,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 163,
                                                        "char": 47
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 163,
                                                "char": 49
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "code",
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
                                                                                "value": "\\t<option selected=\\\"selected\\\" value=\\\"",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 164,
                                                                                "char": 73
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "escaped",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 164,
                                                                                "char": 83
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 164,
                                                                            "char": 83
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "\\\">",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 164,
                                                                            "char": 89
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 164,
                                                                        "char": 89
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "optionText",
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 164,
                                                                        "char": 102
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 164,
                                                                    "char": 102
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "closeOption",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 164,
                                                                    "char": 115
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 164,
                                                                "char": 115
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 164,
                                                            "char": 115
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 165,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "code",
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
                                                                                "value": "\\t<option value=\\\"",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 166,
                                                                                "char": 51
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "escaped",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 166,
                                                                                "char": 61
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 166,
                                                                            "char": 61
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "\\\">",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 166,
                                                                            "char": 67
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 166,
                                                                        "char": 67
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "optionText",
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 166,
                                                                        "char": 80
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 166,
                                                                    "char": 80
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "closeOption",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 166,
                                                                    "char": 93
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 166,
                                                                "char": 93
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 166,
                                                            "char": 93
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 167,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 168,
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
                                                    "variable": "strOptionValue",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "string",
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "optionValue",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 169,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 169,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 169,
                                                    "char": 58
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "strValue",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "string",
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 170,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 170,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 170,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 172,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "strOptionValue",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 172,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "strValue",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 172,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 172,
                                                "char": 48
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "code",
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
                                                                                "value": "\\t<option selected=\\\"selected\\\" value=\\\"",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 173,
                                                                                "char": 73
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "escaped",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 173,
                                                                                "char": 83
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 173,
                                                                            "char": 83
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "\\\">",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 173,
                                                                            "char": 89
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 173,
                                                                        "char": 89
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "optionText",
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 173,
                                                                        "char": 102
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 173,
                                                                    "char": 102
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "closeOption",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 173,
                                                                    "char": 115
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 173,
                                                                "char": 115
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 173,
                                                            "char": 115
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 174,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "code",
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
                                                                                "value": "\\t<option value=\\\"",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 175,
                                                                                "char": 51
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "escaped",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 175,
                                                                                "char": 61
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 175,
                                                                            "char": 61
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "\\\">",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 175,
                                                                            "char": 67
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 175,
                                                                        "char": 67
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "optionText",
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 175,
                                                                        "char": 80
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 175,
                                                                    "char": 80
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "closeOption",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 175,
                                                                    "char": 93
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 175,
                                                                "char": 93
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 175,
                                                            "char": 93
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 176,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 177,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 178,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 180,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 180,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 181,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generate the OPTION tags based on an array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 148,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                        "line": 148,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                    "line": 147,
                    "last-line": 187,
                    "char": 27
                },
                {
                    "visibility": [
                        "private",
                        "static"
                    ],
                    "type": "method",
                    "name": "optionsFromResultset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "resultset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ResulsetInterface",
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 189,
                                "char": 37
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 189,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "using",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 190,
                            "char": 18
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 191,
                            "char": 18
                        },
                        {
                            "type": "parameter",
                            "name": "closeOption",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 193,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 195,
                                    "char": 17
                                },
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 195,
                                    "char": 25
                                },
                                {
                                    "variable": "option",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 195,
                                    "char": 33
                                },
                                {
                                    "variable": "usingZero",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 195,
                                    "char": 44
                                },
                                {
                                    "variable": "usingOne",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 195,
                                    "char": 54
                                },
                                {
                                    "variable": "escaper",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 195,
                                    "char": 63
                                },
                                {
                                    "variable": "optionValue",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 195,
                                    "char": 76
                                },
                                {
                                    "variable": "optionText",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 196,
                                    "char": 23
                                },
                                {
                                    "variable": "strValue",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 196,
                                    "char": 33
                                },
                                {
                                    "variable": "strOptionValue",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 196,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 198,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 198,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 198,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 199,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "params",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 199,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 199,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 201,
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
                                        "value": "using",
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 201,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 201,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 201,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 201,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "fcall",
                                                "name": "count",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "using",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 202,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 202,
                                                        "char": 36
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 202,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "2",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 202,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 202,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 202,
                                        "char": 43
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
                                                            "value": "Parameter 'using' requires two values",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 203,
                                                            "char": 74
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 203,
                                                        "char": 74
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 203,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 204,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 206,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "usingZero",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "using",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 206,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 206,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 206,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 206,
                                            "char": 37
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "usingOne",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "using",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 207,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 207,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 207,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 207,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 208,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 210,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escaper",
                                    "expr": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "EscaperInterface",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 210,
                                            "char": 70
                                        },
                                        "right": {
                                            "type": "scall",
                                            "dynamic-class": 0,
                                            "class": "BaseTag",
                                            "dynamic": 0,
                                            "name": "getEscaperService",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 210,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 210,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 210,
                                    "char": 70
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 212,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "fcall",
                                "name": "iterator",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "resultset",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 212,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 212,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 212,
                                "char": 43
                            },
                            "value": "option",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "using",
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 213,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 213,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 213,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                        "line": 213,
                                        "char": 38
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
                                                        "value": "option",
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 214,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 214,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 214,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 214,
                                                "char": 44
                                            },
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
                                                                    "value": "option",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 215,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 215,
                                                                "char": 44
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "readAttribute",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 215,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 215,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 215,
                                                        "char": 61
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "optionValue",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "option",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 216,
                                                                            "char": 50
                                                                        },
                                                                        "name": "readAttribute",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "usingZero",
                                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                    "line": 216,
                                                                                    "char": 74
                                                                                },
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 216,
                                                                                "char": 74
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 216,
                                                                        "char": 75
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 216,
                                                                    "char": 75
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 217,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "optionText",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "option",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 217,
                                                                            "char": 49
                                                                        },
                                                                        "name": "readAttribute",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "usingOne",
                                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                    "line": 217,
                                                                                    "char": 72
                                                                                },
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 217,
                                                                                "char": 72
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 217,
                                                                        "char": 73
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 217,
                                                                    "char": 73
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 218,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "optionValue",
                                                                    "expr": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "option",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 219,
                                                                            "char": 50
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "usingZero",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 219,
                                                                            "char": 60
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 219,
                                                                        "char": 60
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 219,
                                                                    "char": 60
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 220,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "optionText",
                                                                    "expr": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "option",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 220,
                                                                            "char": 49
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "usingOne",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 220,
                                                                            "char": 58
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 220,
                                                                        "char": 58
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 220,
                                                                    "char": 58
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 221,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 222,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
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
                                                                    "value": "option",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 223,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 223,
                                                                "char": 48
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "array",
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 223,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 223,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 223,
                                                        "char": 56
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
                                                                            "value": "Resultset returned an invalid value",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 226,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 226,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 226,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 227,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 229,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "optionValue",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "option",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 229,
                                                                    "char": 45
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "usingZero",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 229,
                                                                    "char": 55
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 229,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 229,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 230,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "optionText",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "option",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 230,
                                                                    "char": 44
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "usingOne",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 230,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 230,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 230,
                                                            "char": 54
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 231,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 233,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "optionValue",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "escaper",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 233,
                                                            "char": 43
                                                        },
                                                        "name": "escapeHtmlAttr",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "optionValue",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 233,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 233,
                                                                "char": 70
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 233,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 233,
                                                    "char": 71
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 234,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "optionText",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "escaper",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 234,
                                                            "char": 42
                                                        },
                                                        "name": "escapeHtml",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "optionText",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 234,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 234,
                                                                "char": 64
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 234,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 234,
                                                    "char": 65
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 240,
                                            "char": 18
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
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 240,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 240,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 240,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 240,
                                                "char": 42
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "in_array",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "optionValue",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 241,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 241,
                                                                "char": 44
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 241,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 241,
                                                                "char": 51
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 241,
                                                        "char": 53
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "code",
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
                                                                                        "value": "\\t<option selected=\\\"selected\\\" value=\\\"",
                                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                        "line": 242,
                                                                                        "char": 77
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "optionValue",
                                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                        "line": 242,
                                                                                        "char": 91
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                    "line": 242,
                                                                                    "char": 91
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "\\\">",
                                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                    "line": 242,
                                                                                    "char": 97
                                                                                },
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 242,
                                                                                "char": 97
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "optionText",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 242,
                                                                                "char": 110
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 242,
                                                                            "char": 110
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "closeOption",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 242,
                                                                            "char": 123
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 242,
                                                                        "char": 123
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 242,
                                                                    "char": 123
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 243,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "code",
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
                                                                                        "value": "\\t<option value=\\\"",
                                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                        "line": 244,
                                                                                        "char": 55
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "optionValue",
                                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                        "line": 244,
                                                                                        "char": 69
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                    "line": 244,
                                                                                    "char": 69
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "\\\">",
                                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                    "line": 244,
                                                                                    "char": 75
                                                                                },
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 244,
                                                                                "char": 75
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "optionText",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 244,
                                                                                "char": 88
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 244,
                                                                            "char": 88
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "closeOption",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 244,
                                                                            "char": 101
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 244,
                                                                        "char": 101
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 244,
                                                                    "char": 101
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 245,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 246,
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
                                                            "variable": "strOptionValue",
                                                            "expr": {
                                                                "type": "cast",
                                                                "left": "string",
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "optionValue",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 247,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 247,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 247,
                                                            "char": 62
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "strValue",
                                                            "expr": {
                                                                "type": "cast",
                                                                "left": "string",
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 248,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 248,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 248,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 250,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "strOptionValue",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 250,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "strValue",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 250,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 250,
                                                        "char": 52
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "code",
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
                                                                                        "value": "\\t<option selected=\\\"selected\\\" value=\\\"",
                                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                        "line": 251,
                                                                                        "char": 77
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "strOptionValue",
                                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                        "line": 251,
                                                                                        "char": 94
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                    "line": 251,
                                                                                    "char": 94
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "\\\">",
                                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                    "line": 251,
                                                                                    "char": 100
                                                                                },
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 251,
                                                                                "char": 100
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "optionText",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 251,
                                                                                "char": 113
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 251,
                                                                            "char": 113
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "closeOption",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 251,
                                                                            "char": 126
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 251,
                                                                        "char": 126
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 251,
                                                                    "char": 126
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 252,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "concat-assign",
                                                                    "variable": "code",
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
                                                                                        "value": "\\t<option value=\\\"",
                                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                        "line": 253,
                                                                                        "char": 55
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "strOptionValue",
                                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                        "line": 253,
                                                                                        "char": 72
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                    "line": 253,
                                                                                    "char": 72
                                                                                },
                                                                                "right": {
                                                                                    "type": "string",
                                                                                    "value": "\\\">",
                                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                    "line": 253,
                                                                                    "char": 78
                                                                                },
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 253,
                                                                                "char": 78
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "optionText",
                                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                                "line": 253,
                                                                                "char": 91
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 253,
                                                                            "char": 91
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "closeOption",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 253,
                                                                            "char": 104
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 253,
                                                                        "char": 104
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 253,
                                                                    "char": 104
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 254,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 255,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 256,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "using",
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 261,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 261,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 261,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                "line": 261,
                                                "char": 43
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 262,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "null",
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 262,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                        "line": 262,
                                                        "char": 40
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "params",
                                                                    "expr": {
                                                                        "type": "empty-array",
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 263,
                                                                        "char": 40
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 263,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 264,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 266,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "params",
                                                            "index-expr": [
                                                                {
                                                                    "type": "int",
                                                                    "value": "0",
                                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                    "line": 266,
                                                                    "char": 33
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "option",
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 266,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 266,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 267,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "code",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "call_user_func_array",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "using",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 267,
                                                                            "char": 58
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 267,
                                                                        "char": 58
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "params",
                                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                            "line": 267,
                                                                            "char": 66
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                        "line": 267,
                                                                        "char": 66
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                                "line": 267,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                            "line": 267,
                                                            "char": 67
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                                    "line": 268,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                                            "line": 269,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                                    "line": 270,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 272,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 272,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Tag\/Select.zep",
                            "line": 273,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generate the OPTION tags based on a resultset\n     *\n     * @param array using\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag\/Select.zep",
                                "line": 194,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag\/Select.zep",
                        "line": 194,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag\/Select.zep",
                    "line": 188,
                    "last-line": 274,
                    "char": 27
                }
            ],
            "file": "\/app\/phalcon\/Tag\/Select.zep",
            "line": 24,
            "char": 14
        },
        "file": "\/app\/phalcon\/Tag\/Select.zep",
        "line": 24,
        "char": 14
    }
]