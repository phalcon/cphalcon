[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Translate\\Adapter",
        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\Exception",
                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                "line": 14,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                "line": 15,
                "char": 47
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\InterpolatorFactory",
                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                "line": 16,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Translate\\Adapter\n *\n * Base class for Phalcon\\Translate adapters\n *",
        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
        "line": 23,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractAdapter",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "AdapterInterface",
                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
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
                    "name": "defaultInterpolator",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                        "line": 28,
                        "char": 37
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                    "line": 32,
                    "char": 5
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "interpolatorFactory",
                    "docblock": "**\n    * @var InterpolatorFactory\n    *",
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                    "line": 35,
                    "char": 10
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
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 35,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 35,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 35,
                            "char": 83
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
                                    "property": "defaultInterpolator",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Arr",
                                        "dynamic": 0,
                                        "name": "get",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                                    "line": 37,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                                "line": 37,
                                                "char": 57
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "defaultInterpolator",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                                    "line": 37,
                                                    "char": 78
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                                "line": 37,
                                                "char": 78
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "associativeArray",
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                                    "line": 37,
                                                    "char": 96
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                                "line": 37,
                                                "char": 96
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 37,
                                        "char": 97
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                    "line": 37,
                                    "char": 97
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "interpolatorFactory",
                                    "expr": {
                                        "type": "variable",
                                        "value": "interpolator",
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 38,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                    "line": 38,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 39,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                    "line": 35,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "_",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "translateKey",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 46,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 46,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 46,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                    "line": 48,
                                    "char": 21
                                },
                                "name": "query",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "translateKey",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                            "line": 48,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 48,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "placeholders",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                            "line": 48,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 48,
                                        "char": 56
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 48,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 49,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the translation string of the given key (alias of method 't')\n     *\n     * @param array   placeholders\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 47,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                        "line": 47,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                    "line": 46,
                    "last-line": 53,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetExists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "translateKey",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 54,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                    "line": 56,
                                    "char": 21
                                },
                                "name": "exists",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "translateKey",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                            "line": 56,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 56,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 56,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 57,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether a translation key exists\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 55,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                        "line": 55,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                    "line": 54,
                    "last-line": 61,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetGet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "translateKey",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 62,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                    "line": 64,
                                    "char": 21
                                },
                                "name": "query",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "translateKey",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                            "line": 64,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 64,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                            "line": 64,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 64,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 64,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 65,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the translation related to the given key\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 63,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                        "line": 63,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                    "line": 62,
                    "last-line": 71,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetSet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "offset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 72,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 72,
                            "char": 52
                        }
                    ],
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
                                            "value": "Translate is an immutable ArrayAccess object",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                            "line": 74,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 74,
                                        "char": 73
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 74,
                                "char": 74
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 75,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a translation value\n     *\n     * @param string value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                        "line": 73,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                    "line": 72,
                    "last-line": 79,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetUnset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "offset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 80,
                            "char": 43
                        }
                    ],
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
                                            "value": "Translate is an immutable ArrayAccess object",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                            "line": 82,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 82,
                                        "char": 73
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 82,
                                "char": 74
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 83,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Unsets a translation from the dictionary\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                        "line": 81,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                    "line": 80,
                    "last-line": 89,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "t",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "translateKey",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 90,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 90,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 90,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                    "line": 92,
                                    "char": 21
                                },
                                "name": "query",
                                "call-type": 3,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "translateKey",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                            "line": 92,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 92,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "placeholders",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                            "line": 92,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 92,
                                        "char": 56
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 92,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 93,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the translation string of the given key\n     *\n     * @param array   placeholders\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 91,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                        "line": 91,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                    "line": 90,
                    "last-line": 97,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "replacePlaceholders",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "translation",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 98,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "placeholders",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 98,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 98,
                            "char": 84
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "interpolator",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                    "line": 100,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 102,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "interpolator",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                                "line": 102,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "interpolatorFactory",
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                                "line": 102,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                            "line": 102,
                                            "char": 54
                                        },
                                        "name": "newInstance",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                                        "line": 102,
                                                        "char": 72
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "defaultInterpolator",
                                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                                        "line": 102,
                                                        "char": 92
                                                    },
                                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                                    "line": 102,
                                                    "char": 92
                                                },
                                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                                "line": 102,
                                                "char": 92
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 102,
                                        "char": 93
                                    },
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                    "line": 102,
                                    "char": 93
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 104,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "interpolator",
                                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                    "line": 104,
                                    "char": 29
                                },
                                "name": "replacePlaceholders",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "translation",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                            "line": 105,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 105,
                                        "char": 24
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "placeholders",
                                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                            "line": 107,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                        "line": 107,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 107,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                            "line": 108,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Replaces placeholders by the values passed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                                "line": 99,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                        "line": 99,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
                    "line": 98,
                    "last-line": 109,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
            "line": 23,
            "char": 14
        },
        "file": "\/app\/phalcon\/Translate\/Adapter\/AbstractAdapter.zep",
        "line": 23,
        "char": 14
    }
]