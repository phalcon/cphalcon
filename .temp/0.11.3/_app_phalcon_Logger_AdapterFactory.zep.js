[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger",
        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\AbstractFactory",
                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                "line": 13,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
        "line": 15,
        "char": 5
    },
    {
        "type": "class",
        "name": "AdapterFactory",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractFactory",
        "definition": {
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
                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                "line": 20,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                            "line": 20,
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
                                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                    "line": 22,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                            "line": 22,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                        "line": 22,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                "line": 22,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                            "line": 23,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * AdapterFactory constructor.\n     *",
                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                    "line": 20,
                    "last-line": 27,
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
                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                            "line": 29,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "fileName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                            "line": 30,
                            "char": 25
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                "line": 32,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                            "line": 32,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                    "line": 34,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                            "line": 36,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                    "line": 36,
                                    "char": 14
                                },
                                "name": "checkService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                            "line": 36,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                        "line": 36,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                "line": 36,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                            "line": 38,
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
                                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                "line": 38,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "services",
                                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                "line": 38,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                            "line": 38,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                            "line": 38,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                        "line": 38,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                    "line": 38,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                "line": 38,
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
                                                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                        "line": 39,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mapper",
                                                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                        "line": 39,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                    "line": 39,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                    "line": 39,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                "line": 39,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                            "line": 39,
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
                                                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                    "line": 40,
                                                    "char": 36
                                                }
                                            ],
                                            "expr": {
                                                "type": "new",
                                                "class": "definition",
                                                "dynamic": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "fileName",
                                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                            "line": 40,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                        "line": 40,
                                                        "char": 65
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                            "line": 40,
                                                            "char": 74
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                        "line": 40,
                                                        "char": 74
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                                "line": 40,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                            "line": 40,
                                            "char": 75
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                    "line": 41,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                            "line": 43,
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
                                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                        "line": 43,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                        "line": 43,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                    "line": 43,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                    "line": 43,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                "line": 43,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                            "line": 44,
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
                                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                    "line": 33,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                "line": 33,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                        "line": 33,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                    "line": 28,
                    "last-line": 46,
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
                                            "value": "noop",
                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                            "line": 49,
                                            "char": 20
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Logger\\\\Adapter\\\\Noop",
                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                            "line": 49,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                        "line": 49,
                                        "char": 54
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "stream",
                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                            "line": 50,
                                            "char": 20
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Logger\\\\Adapter\\\\Stream",
                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                            "line": 50,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                        "line": 50,
                                        "char": 56
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "syslog",
                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                            "line": 51,
                                            "char": 20
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Logger\\\\Adapter\\\\Syslog",
                                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                            "line": 52,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                        "line": 52,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                "line": 52,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                            "line": 53,
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
                                "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                                "line": 47,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                        "line": 47,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
                    "line": 46,
                    "last-line": 54,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
            "line": 15,
            "char": 5
        },
        "file": "\/app\/phalcon\/Logger\/AdapterFactory.zep",
        "line": 15,
        "char": 5
    }
]