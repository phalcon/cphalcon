[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Html\\Helper",
        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Html\\Exception",
                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                "line": 13,
                "char": 27
            }
        ],
        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\EscaperInterface",
                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                "line": 14,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Html\\Helper\\AbstractHelper\n *\n * Abstract class for all html helpers\n *",
        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
        "line": 21,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractHelper",
        "abstract": 1,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "escaper",
                    "docblock": "**\n     * @var <EscaperInterface>\n     *",
                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                    "line": 30,
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
                            "name": "escaper",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "EscaperInterface",
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 31,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 31,
                            "char": 59
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
                                    "property": "escaper",
                                    "expr": {
                                        "type": "variable",
                                        "value": "escaper",
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 33,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 33,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 34,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor\n     *",
                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                    "line": 31,
                    "last-line": 38,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "renderFullElement",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tag",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 40,
                            "char": 19
                        },
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 41,
                            "char": 20
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 42,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 42,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "raw",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 44,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 44,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "content",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 46,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 48,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "content",
                                    "expr": {
                                        "type": "ternary",
                                        "left": {
                                            "type": "variable",
                                            "value": "raw",
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 48,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 48,
                                            "char": 34
                                        },
                                        "extra": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 48,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "escaper",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 48,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 48,
                                                "char": 50
                                            },
                                            "name": "escapeHtml",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "text",
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 48,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 48,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 48,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 48,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 48,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 50,
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
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 50,
                                                    "char": 21
                                                },
                                                "name": "renderElement",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "tag",
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 50,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 50,
                                                        "char": 39
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "attributes",
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 50,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 50,
                                                        "char": 51
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 50,
                                                "char": 53
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "content",
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 50,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 50,
                                            "char": 63
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "<\/",
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 50,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 50,
                                        "char": 68
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "tag",
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 50,
                                        "char": 74
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 50,
                                    "char": 74
                                },
                                "right": {
                                    "type": "string",
                                    "value": ">",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 50,
                                    "char": 77
                                },
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 50,
                                "char": 77
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 51,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders an element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 44,
                                "char": 17
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                        "line": 44,
                        "char": 17
                    },
                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                    "line": 39,
                    "last-line": 55,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "renderElement",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tag",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 56,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 56,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 56,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "attrs",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 58,
                                    "char": 18
                                },
                                {
                                    "variable": "escapedAttrs",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 58,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 60,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escapedAttrs",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 60,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 60,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 61,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "fcall",
                                    "name": "count",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "attributes",
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 61,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 61,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 61,
                                    "char": 30
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 61,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 61,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "attrs",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 62,
                                                    "char": 37
                                                },
                                                "name": "orderAttributes",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "empty-array",
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 62,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 62,
                                                        "char": 56
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "attributes",
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 62,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 62,
                                                        "char": 68
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 62,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 62,
                                            "char": 69
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "escapedAttrs",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": " ",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 63,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "rtrim",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                    "line": 63,
                                                                    "char": 47
                                                                },
                                                                "name": "renderAttributes",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "attrs",
                                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                            "line": 63,
                                                                            "char": 70
                                                                        },
                                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                        "line": 63,
                                                                        "char": 70
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                "line": 63,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 63,
                                                            "char": 71
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 63,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 63,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 63,
                                            "char": 72
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 64,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 66,
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
                                            "type": "string",
                                            "value": "<",
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 66,
                                            "char": 18
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "tag",
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 66,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 66,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "escapedAttrs",
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 66,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 66,
                                    "char": 39
                                },
                                "right": {
                                    "type": "string",
                                    "value": ">",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 66,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 66,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 67,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders an element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 57,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                        "line": 57,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                    "line": 56,
                    "last-line": 76,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "orderAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "overrides",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 77,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 77,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "intersect",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 79,
                                    "char": 22
                                },
                                {
                                    "variable": "order",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 79,
                                    "char": 29
                                },
                                {
                                    "variable": "results",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 79,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 81,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "order",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "rel",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 82,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 82,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 82,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 83,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 83,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 83,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "for",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 84,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 84,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 84,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "src",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 85,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 85,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 85,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "href",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 86,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 86,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 86,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "action",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 87,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 87,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 87,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "id",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 88,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 88,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 88,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 89,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 89,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 89,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 90,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 90,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 90,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "class",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 91,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 92,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 92,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 92,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 92,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 94,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "intersect",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_intersect_key",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "order",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 94,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 94,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "attributes",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 94,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 94,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 94,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 94,
                                    "char": 63
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "results",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "intersect",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 95,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 95,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "attributes",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 95,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 95,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 95,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 95,
                                    "char": 59
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "results",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "overrides",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 96,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 96,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "results",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 96,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 96,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 96,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 96,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 101,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "variable",
                                    "value": "results",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 101,
                                    "char": 22
                                },
                                "right": {
                                    "type": "string",
                                    "value": "escape",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 101,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 101,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 103,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "results",
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 103,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 104,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Keeps all the attributes sorted - same order all the tome\n     *\n     * @param array overrides\n     * @param array attributes\n     *\n     * @return array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 78,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                        "line": 78,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                    "line": 77,
                    "last-line": 108,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "renderAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 109,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 111,
                                    "char": 16
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 111,
                                    "char": 24
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 111,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 113,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 113,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 113,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 114,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "attributes",
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 114,
                                "char": 38
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "identical",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 115,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 115,
                                                "char": 29
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 115,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 115,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 115,
                                                "char": 48
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 115,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 115,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 115,
                                        "char": 56
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "or",
                                                "left": {
                                                    "type": "or",
                                                    "left": {
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "typeof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                "line": 116,
                                                                "char": 35
                                                            },
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 116,
                                                            "char": 35
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "array",
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 116,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 116,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "typeof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                "line": 117,
                                                                "char": 35
                                                            },
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 117,
                                                            "char": 35
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "resource",
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 117,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 117,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 117,
                                                    "char": 47
                                                },
                                                "right": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 118,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 118,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 118,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 118,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 118,
                                                "char": 44
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
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "string",
                                                                                    "value": "Value at index: \\\"",
                                                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                                    "line": 120,
                                                                                    "char": 44
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "key",
                                                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                                    "line": 120,
                                                                                    "char": 50
                                                                                },
                                                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                                "line": 120,
                                                                                "char": 50
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "\\\" type: \\\"",
                                                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                                "line": 120,
                                                                                "char": 64
                                                                            },
                                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                            "line": 120,
                                                                            "char": 64
                                                                        },
                                                                        "right": {
                                                                            "type": "fcall",
                                                                            "name": "gettype",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "value",
                                                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                                        "line": 120,
                                                                                        "char": 79
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                                    "line": 120,
                                                                                    "char": 79
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                            "line": 120,
                                                                            "char": 81
                                                                        },
                                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                        "line": 120,
                                                                        "char": 81
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "\\\" cannot be rendered",
                                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                        "line": 121,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                    "line": 121,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                "line": 121,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 121,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 122,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 124,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "result",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "key",
                                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                    "line": 124,
                                                                    "char": 34
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "=\\\"",
                                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                    "line": 124,
                                                                    "char": 40
                                                                },
                                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                "line": 124,
                                                                "char": 40
                                                            },
                                                            "right": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                        "line": 124,
                                                                        "char": 47
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "escaper",
                                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                        "line": 124,
                                                                        "char": 56
                                                                    },
                                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                    "line": 124,
                                                                    "char": 56
                                                                },
                                                                "name": "escapeHtmlAttr",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "value",
                                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                            "line": 124,
                                                                            "char": 77
                                                                        },
                                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                        "line": 124,
                                                                        "char": 77
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                "line": 124,
                                                                "char": 79
                                                            },
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 124,
                                                            "char": 79
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "\\\" ",
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 124,
                                                            "char": 84
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 124,
                                                        "char": 84
                                                    },
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 124,
                                                    "char": 84
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 125,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 126,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 128,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 128,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 129,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders all the attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 110,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                        "line": 110,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                    "line": 109,
                    "last-line": 133,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "selfClose",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tag",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 134,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 134,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 134,
                            "char": 69
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "attrs",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 136,
                                    "char": 18
                                },
                                {
                                    "variable": "escapedAttrs",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 136,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 138,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escapedAttrs",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 138,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 138,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 139,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "fcall",
                                    "name": "count",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "attributes",
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 139,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 139,
                                            "char": 28
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 139,
                                    "char": 30
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 139,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 139,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "attrs",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 140,
                                                    "char": 37
                                                },
                                                "name": "orderAttributes",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "empty-array",
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 140,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 140,
                                                        "char": 56
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "attributes",
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 140,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                        "line": 140,
                                                        "char": 68
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 140,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 140,
                                            "char": 69
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "escapedAttrs",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": " ",
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 141,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "rtrim",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                    "line": 141,
                                                                    "char": 47
                                                                },
                                                                "name": "renderAttributes",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "attrs",
                                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                            "line": 141,
                                                                            "char": 70
                                                                        },
                                                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                        "line": 141,
                                                                        "char": 70
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                                "line": 141,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                            "line": 141,
                                                            "char": 71
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                    "line": 141,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                                "line": 141,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 141,
                                            "char": 72
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 142,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 144,
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
                                            "type": "string",
                                            "value": "<",
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 144,
                                            "char": 18
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "tag",
                                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                            "line": 144,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 144,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "escapedAttrs",
                                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                        "line": 144,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 144,
                                    "char": 39
                                },
                                "right": {
                                    "type": "string",
                                    "value": "\/>",
                                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                    "line": 144,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 144,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                            "line": 145,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Produces a self close tag i.e. <img \/>\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                                "line": 135,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                        "line": 135,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
                    "line": 134,
                    "last-line": 146,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
            "line": 21,
            "char": 14
        },
        "file": "\/app\/phalcon\/Html\/Helper\/AbstractHelper.zep",
        "line": 21,
        "char": 14
    }
]