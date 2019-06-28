[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Micro",
        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\BinderInterface",
                "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                "line": 13,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Micro\\LazyLoader\n *\n * Lazy-Load of handlers for Mvc\\Micro using auto-loading\n *",
        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "LazyLoader",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "handler",
                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                    "line": 24,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "definition",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                            "line": 24,
                            "char": 32
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                    "line": 28,
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
                            "name": "definition",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                            "line": 29,
                            "char": 51
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
                                    "property": "definition",
                                    "expr": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                        "line": 31,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 31,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                            "line": 32,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Micro\\LazyLoader constructor\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                    "line": 29,
                    "last-line": 39,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "callMethod",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                            "line": 40,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "arguments",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                            "line": 40,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "modelBinder",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "BinderInterface",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                "line": 40,
                                "char": 87
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                "line": 40,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                            "line": 40,
                            "char": 95
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "handler",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 42,
                                    "char": 21
                                },
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 42,
                                    "char": 33
                                },
                                {
                                    "variable": "bindCacheKey",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 42,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                            "line": 44,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "handler",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                            "line": 44,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                            "line": 44,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                        "line": 44,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 44,
                                    "char": 39
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "definition",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                            "line": 45,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "definition",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                            "line": 45,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                        "line": 45,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 45,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                            "line": 47,
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
                                        "value": "handler",
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                        "line": 47,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 47,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 47,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                "line": 47,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handler",
                                            "expr": {
                                                "type": "new",
                                                "class": "definition",
                                                "dynamic": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                "line": 48,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                            "line": 48,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 50,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "handler",
                                            "expr": {
                                                "type": "variable",
                                                "value": "handler",
                                                "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                "line": 50,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                            "line": 50,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 51,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                            "line": 53,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "modelBinder",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 53,
                                    "char": 25
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 53,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                "line": 53,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "bindCacheKey",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "_PHMB_",
                                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                            "line": 54,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "definition",
                                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                            "line": 54,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                        "line": 54,
                                                        "char": 52
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "_",
                                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                        "line": 54,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                    "line": 54,
                                                    "char": 56
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "method",
                                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                    "line": 54,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                "line": 54,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                            "line": 54,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 56,
                                    "char": 15
                                },
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
                                                    "value": "modelBinder",
                                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                    "line": 56,
                                                    "char": 41
                                                },
                                                "name": "bindToHandler",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "handler",
                                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                            "line": 57,
                                                            "char": 24
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                        "line": 57,
                                                        "char": 24
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "arguments",
                                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                            "line": 58,
                                                            "char": 26
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                        "line": 58,
                                                        "char": 26
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "bindCacheKey",
                                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                            "line": 59,
                                                            "char": 29
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                        "line": 59,
                                                        "char": 29
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "method",
                                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                            "line": 61,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                        "line": 61,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                "line": 61,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                            "line": 61,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                    "line": 62,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                            "line": 67,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "call_user_func_array",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "handler",
                                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                        "line": 68,
                                                        "char": 21
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                    "line": 68,
                                                    "char": 21
                                                },
                                                {
                                                    "value": {
                                                        "type": "variable",
                                                        "value": "method",
                                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                        "line": 68,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                                    "line": 68,
                                                    "char": 29
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                            "line": 68,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                        "line": 68,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "arguments",
                                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                            "line": 70,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                        "line": 70,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                                "line": 70,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                            "line": 71,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Calling __call method\n     *\n     * @param  array arguments\n     * @return mixed\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
                    "line": 40,
                    "last-line": 72,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Micro\/LazyLoader.zep",
        "line": 20,
        "char": 5
    }
]