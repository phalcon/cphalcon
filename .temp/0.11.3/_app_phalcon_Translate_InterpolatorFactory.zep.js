[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Translate",
        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\AbstractFactory",
                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                "line": 13,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Translate\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                "line": 14,
                "char": 47
            }
        ],
        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
        "line": 16,
        "char": 5
    },
    {
        "type": "class",
        "name": "InterpolatorFactory",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractFactory",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "mapper",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                        "line": 21,
                        "char": 26
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                    "line": 25,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "services",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                        "line": 26,
                        "char": 26
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
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
                            "name": "services",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                "line": 31,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                            "line": 31,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                    "line": 33,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                            "line": 33,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                        "line": 33,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                "line": 33,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                            "line": 34,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * AdapterFactory constructor.\n     *",
                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                    "line": 31,
                    "last-line": 38,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "newInstance",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                            "line": 39,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                    "line": 41,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                            "line": 43,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                    "line": 43,
                                    "char": 14
                                },
                                "name": "checkService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                            "line": 43,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                        "line": 43,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                "line": 43,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                            "line": 45,
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
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                                "line": 45,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "services",
                                                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                                "line": 45,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                            "line": 45,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                            "line": 45,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                        "line": 45,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                    "line": 45,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                "line": 45,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "definition",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                                        "line": 46,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mapper",
                                                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                                        "line": 46,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                                    "line": 46,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                                    "line": 46,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                                "line": 46,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                            "line": 46,
                                            "char": 58
                                        },
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "services",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                                    "line": 47,
                                                    "char": 36
                                                }
                                            ],
                                            "expr": {
                                                "type": "new",
                                                "class": "definition",
                                                "dynamic": 1,
                                                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                                "line": 47,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                            "line": 47,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                    "line": 48,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                            "line": 50,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                        "line": 50,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                        "line": 50,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                    "line": 50,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                    "line": 50,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                "line": 50,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                            "line": 51,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Create a new instance of the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                    "line": 40,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                "line": 40,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                        "line": 40,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                    "line": 39,
                    "last-line": 53,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getAdapters",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "associativeArray",
                                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                            "line": 56,
                                            "char": 30
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Translate\\\\Interpolator\\\\AssociativeArray",
                                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                            "line": 56,
                                            "char": 84
                                        },
                                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                        "line": 56,
                                        "char": 84
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "indexedArray",
                                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                            "line": 57,
                                            "char": 30
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Translate\\\\Interpolator\\\\IndexedArray",
                                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                            "line": 58,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                        "line": 58,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                "line": 58,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                            "line": 59,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                                "line": 54,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                        "line": 54,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
                    "line": 53,
                    "last-line": 60,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
            "line": 16,
            "char": 5
        },
        "file": "\/app\/phalcon\/Translate\/InterpolatorFactory.zep",
        "line": 16,
        "char": 5
    }
]