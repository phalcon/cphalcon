[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Translate\\Adapter",
        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ArrayAccess",
                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                "line": 13,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\Exception",
                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                "line": 14,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                "line": 15,
                "char": 46
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\InterpolatorFactory",
                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                "line": 16,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Translate\\Adapter\\Csv\n *\n * Allows to define translation lists using CSV file\n *",
        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
        "line": 23,
        "char": 5
    },
    {
        "type": "class",
        "name": "Csv",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractAdapter",
        "implements": [
            {
                "type": "variable",
                "value": "ArrayAccess",
                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                "line": 24,
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
                    "name": "translate",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                        "line": 28,
                        "char": 29
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
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
                            "name": "interpolator",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "InterpolatorFactory",
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 33,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 33,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 33,
                            "char": 83
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "delimiter",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 35,
                                    "char": 22
                                },
                                {
                                    "variable": "enclosure",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 35,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 37,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "__construct",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "interpolator",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 37,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 37,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 37,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 37,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 37,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 39,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 39,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "content",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 39,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 39,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 39,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 39,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 39,
                                "char": 45
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
                                                    "value": "Parameter 'content' is required",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                    "line": 40,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 40,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 40,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 41,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 43,
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
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 43,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "delimiter",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 43,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 43,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 43,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "delimiter",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                    "line": 44,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "delimiter",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                    "line": 44,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 44,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 44,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 45,
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
                                            "variable": "delimiter",
                                            "expr": {
                                                "type": "string",
                                                "value": ";",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 46,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 46,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 47,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 49,
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
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 49,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "enclosure",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 49,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 49,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 49,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "enclosure",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                    "line": 50,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "enclosure",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                    "line": 50,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 50,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 50,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 51,
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
                                            "variable": "enclosure",
                                            "expr": {
                                                "type": "string",
                                                "value": "\\\"",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 52,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 52,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 53,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 55,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 55,
                                    "char": 14
                                },
                                "name": "load",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 55,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "content",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 55,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 55,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 55,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 55,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 55,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "delimiter",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 55,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 55,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "enclosure",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 55,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 55,
                                        "char": 61
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 55,
                                "char": 62
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 56,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Translate\\Adapter\\Csv constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                        "line": 34,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                    "line": 33,
                    "last-line": 60,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "exists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 61,
                            "char": 41
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
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 63,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "translate",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 63,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 63,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "index",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 63,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 63,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 63,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 64,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether is defined a translation key in the internal array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 62,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                        "line": 62,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                    "line": 61,
                    "last-line": 68,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "query",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 69,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 69,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 69,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "translation",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 71,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 73,
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
                                        "value": "translation",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 73,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 73,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "translate",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 73,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 73,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "index",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 73,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 73,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 73,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 73,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "translation",
                                            "expr": {
                                                "type": "variable",
                                                "value": "index",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 74,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 74,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 75,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 77,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 77,
                                    "char": 21
                                },
                                "name": "replacePlaceholders",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "translation",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 77,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 77,
                                        "char": 53
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "placeholders",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 77,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 77,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 77,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 78,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the translation related to the given key\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 70,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                        "line": 70,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                    "line": 69,
                    "last-line": 82,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "load",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "file",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 83,
                            "char": 38
                        },
                        {
                            "type": "parameter",
                            "name": "length",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 83,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "delimiter",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 83,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "enclosure",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 83,
                            "char": 86
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 85,
                                    "char": 17
                                },
                                {
                                    "variable": "fileHandler",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 85,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 87,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "fileHandler",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "fopen",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                    "line": 87,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 87,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "rb",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                    "line": 87,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 87,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 87,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 87,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 89,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "fileHandler",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 89,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 89,
                                        "char": 42
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "resource",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 89,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 89,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 89,
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "Error opening translation file '",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                            "line": 91,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                            "line": 91,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 91,
                                                        "char": 57
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "'",
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 92,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                    "line": 92,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 92,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 92,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 93,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 95,
                            "char": 12
                        },
                        {
                            "type": "loop",
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "data",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "fgetcsv",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "fileHandler",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                            "line": 96,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 96,
                                                        "char": 43
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "length",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                            "line": 96,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 96,
                                                        "char": 51
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "delimiter",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                            "line": 96,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 96,
                                                        "char": 62
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "enclosure",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                            "line": 96,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 96,
                                                        "char": 73
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 96,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 96,
                                            "char": 74
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 98,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 98,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 98,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 98,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 100,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 102,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "or",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "fcall",
                                                "name": "substr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "data",
                                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                                "line": 102,
                                                                "char": 27
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "0",
                                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                                "line": 102,
                                                                "char": 29
                                                            },
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                            "line": 102,
                                                            "char": 30
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 102,
                                                        "char": 30
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                            "line": 102,
                                                            "char": 33
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 102,
                                                        "char": 33
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                            "line": 102,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 102,
                                                        "char": 36
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 102,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "#",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 102,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 102,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 102,
                                                        "char": 58
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 102,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                    "line": 102,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 102,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 102,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 102,
                                        "char": 62
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 104,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 106,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "translate",
                                            "index-expr": [
                                                {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 106,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                        "line": 106,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                    "line": 106,
                                                    "char": 40
                                                }
                                            ],
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                    "line": 106,
                                                    "char": 48
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                    "line": 106,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                                "line": 106,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 106,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                    "line": 107,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 109,
                            "char": 14
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "fclose",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "fileHandler",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                            "line": 109,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                        "line": 109,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                                "line": 109,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                            "line": 110,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Load translates from file\n    *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                        "line": 84,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
                    "line": 83,
                    "last-line": 111,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
            "line": 23,
            "char": 5
        },
        "file": "\/app\/phalcon\/Translate\/Adapter\/Csv.zep",
        "line": 23,
        "char": 5
    }
]