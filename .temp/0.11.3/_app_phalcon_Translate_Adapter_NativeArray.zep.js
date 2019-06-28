[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Translate\\Adapter",
        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ArrayAccess",
                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                "line": 13,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\Exception",
                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                "line": 14,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                "line": 15,
                "char": 46
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\InterpolatorFactory",
                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                "line": 16,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Translate\\Adapter\\NativeArray\n *\n * Allows to define translation lists using PHP arrays\n *",
        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
        "line": 23,
        "char": 5
    },
    {
        "type": "class",
        "name": "NativeArray",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractAdapter",
        "implements": [
            {
                "type": "variable",
                "value": "ArrayAccess",
                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                "line": 24,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "translate",
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                    "line": 32,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "triggerError",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                        "line": 33,
                        "char": 33
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                    "line": 37,
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
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 38,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 38,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 38,
                            "char": 83
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 40,
                                    "char": 17
                                },
                                {
                                    "variable": "error",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 40,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 42,
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
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 42,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 42,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 42,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 42,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 42,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 44,
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 44,
                                            "char": 51
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                "line": 44,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "content",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                "line": 44,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 44,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 44,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 44,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 44,
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
                                                    "value": "Translation content was not provided",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                    "line": 45,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                "line": 45,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 45,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 46,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 48,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "error",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 48,
                                    "char": 47
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 48,
                                        "char": 32
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "triggerError",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 48,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 48,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 48,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "triggerError",
                                            "expr": {
                                                "type": "cast",
                                                "left": "bool",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "error",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                    "line": 49,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                "line": 49,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 49,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 50,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 52,
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
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 52,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 52,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 52,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 52,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 52,
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
                                                    "value": "Translation data must be an array",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                    "line": 53,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                "line": 53,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 53,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 54,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 56,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "translate",
                                    "expr": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 56,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 56,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 57,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Translate\\Adapter\\NativeArray constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                        "line": 39,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                    "line": 38,
                    "last-line": 61,
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
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 62,
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
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 64,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "translate",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 64,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 64,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "index",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 64,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 64,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 64,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 65,
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
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 63,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                        "line": 63,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                    "line": 62,
                    "last-line": 69,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notFound",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 70,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "identical",
                                        "left": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 72,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                "line": 72,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "triggerError",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                "line": 72,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 72,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 72,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 72,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 72,
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "Cannot find translation key: ",
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                        "line": 73,
                                                        "char": 63
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "index",
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                        "line": 73,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                    "line": 73,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                "line": 73,
                                                "char": 70
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 73,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 74,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 76,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "index",
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 76,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 77,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Whenever a key is not found this medhod will be called\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 71,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                        "line": 71,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                    "line": 70,
                    "last-line": 81,
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
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 82,
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
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 82,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 82,
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
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 84,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
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
                                        "value": "translation",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 86,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                "line": 86,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "translate",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                "line": 86,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 86,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "index",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 86,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 86,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 86,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 86,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 87,
                                            "char": 25
                                        },
                                        "name": "notFound",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "index",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                    "line": 87,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                                "line": 87,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 87,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 88,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 90,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                    "line": 90,
                                    "char": 21
                                },
                                "name": "replacePlaceholders",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "translation",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 90,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 90,
                                        "char": 53
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "placeholders",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                            "line": 90,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                        "line": 90,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 90,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                            "line": 91,
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
                                "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                                "line": 83,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                        "line": 83,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
                    "line": 82,
                    "last-line": 92,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
            "line": 23,
            "char": 5
        },
        "file": "\/app\/phalcon\/Translate\/Adapter\/NativeArray.zep",
        "line": 23,
        "char": 5
    }
]