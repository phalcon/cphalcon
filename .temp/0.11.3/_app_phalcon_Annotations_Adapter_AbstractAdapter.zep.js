[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Annotations\\Adapter",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                "line": 13,
                "char": 49
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Reader",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                "line": 14,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Exception",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                "line": 15,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Collection",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                "line": 16,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Reflection",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                "line": 17,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\ReaderInterface",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                "line": 18,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This is the base class for Phalcon\\Annotations adapters\n *",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
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
                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
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
                    "name": "annotations",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                        "line": 28,
                        "char": 31
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                    "line": 32,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "reader",
                    "docblock": "**\n     * @var Reader\n     *",
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
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
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 38,
                            "char": 38
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "classAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 40,
                                    "char": 29
                                },
                                {
                                    "variable": "parsedAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 40,
                                    "char": 48
                                },
                                {
                                    "variable": "realClassName",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 40,
                                    "char": 63
                                },
                                {
                                    "variable": "reader",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 40,
                                    "char": 71
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 45,
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
                                        "value": "className",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 45,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 45,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 45,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 45,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "realClassName",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "get_class",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "className",
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                            "line": 46,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                        "line": 46,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 46,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 46,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 47,
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
                                            "variable": "realClassName",
                                            "expr": {
                                                "type": "variable",
                                                "value": "className",
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 48,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 48,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 49,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 51,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 51,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "annotations",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 51,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 51,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "realClassName",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 51,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 51,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 51,
                                "char": 51
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 52,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "annotations",
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 52,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 52,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "realClassName",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 52,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 52,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 53,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 58,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "classAnnotations",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 58,
                                            "char": 37
                                        },
                                        "name": "read",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "realClassName",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                    "line": 58,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 58,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 58,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 58,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 60,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "variable",
                                        "value": "classAnnotations",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 60,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 60,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 60,
                                    "char": 39
                                },
                                "right": {
                                    "type": "identical",
                                    "left": {
                                        "type": "variable",
                                        "value": "classAnnotations",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 60,
                                        "char": 60
                                    },
                                    "right": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 60,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 60,
                                    "char": 68
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 60,
                                "char": 68
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "reader",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                    "line": 64,
                                                    "char": 31
                                                },
                                                "name": "getReader",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 64,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 64,
                                            "char": 43
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "parsedAnnotations",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "reader",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                    "line": 65,
                                                    "char": 44
                                                },
                                                "name": "parse",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "realClassName",
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                            "line": 65,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                        "line": 65,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 65,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 65,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 67,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "classAnnotations",
                                            "expr": {
                                                "type": "new",
                                                "class": "Reflection",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "parsedAnnotations",
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                            "line": 67,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                        "line": 67,
                                                        "char": 68
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 67,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 67,
                                            "char": 69
                                        },
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "annotations",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "realClassName",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                    "line": 68,
                                                    "char": 48
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "classAnnotations",
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 68,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 68,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 69,
                                    "char": 20
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 69,
                                            "char": 22
                                        },
                                        "name": "write",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "realClassName",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                    "line": 69,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 69,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "classAnnotations",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                    "line": 69,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 69,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 69,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 70,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 72,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "classAnnotations",
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 72,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 73,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Parses or retrieves all the annotations found in a class\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Reflection",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 39,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 39,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                        "line": 39,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                    "line": 38,
                    "last-line": 77,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMethod",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 78,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "methodName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 78,
                            "char": 66
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "classAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 80,
                                    "char": 29
                                },
                                {
                                    "variable": "methods",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 80,
                                    "char": 38
                                },
                                {
                                    "variable": "method",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 80,
                                    "char": 46
                                },
                                {
                                    "variable": "methodKey",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 80,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 85,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "classAnnotations",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 85,
                                            "char": 37
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                    "line": 85,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 85,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 85,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 85,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 87,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "methods",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "classAnnotations",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 87,
                                            "char": 40
                                        },
                                        "name": "getMethodsAnnotations",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 87,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 87,
                                    "char": 64
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 89,
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
                                        "value": "methods",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 89,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 89,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 89,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 89,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "methods",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 90,
                                        "char": 46
                                    },
                                    "key": "methodKey",
                                    "value": "method",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "strcasecmp",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "methodKey",
                                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                                "line": 91,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                            "line": 91,
                                                            "char": 41
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "methodName",
                                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                                "line": 91,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                            "line": 91,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                    "line": 91,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 91,
                                                "char": 55
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "method",
                                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                        "line": 92,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                    "line": 93,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 94,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 95,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 100,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "Collection",
                                "dynamic": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 100,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 101,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the annotations found in a specific method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 79,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 79,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                        "line": 79,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                    "line": 78,
                    "last-line": 105,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMethods",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 106,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "classAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 108,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 113,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "classAnnotations",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 113,
                                            "char": 37
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                    "line": 113,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 113,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 113,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 113,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 115,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "classAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 115,
                                    "char": 33
                                },
                                "name": "getMethodsAnnotations",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 115,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 116,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the annotations found in all the class' methods\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 107,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                        "line": 107,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                    "line": 106,
                    "last-line": 120,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getProperty",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 121,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "propertyName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 121,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "classAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 123,
                                    "char": 29
                                },
                                {
                                    "variable": "properties",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 123,
                                    "char": 41
                                },
                                {
                                    "variable": "property",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 123,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 128,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "classAnnotations",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 128,
                                            "char": 37
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                    "line": 128,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 128,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 128,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 128,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 130,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "properties",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "classAnnotations",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 130,
                                            "char": 43
                                        },
                                        "name": "getPropertiesAnnotations",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 130,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 130,
                                    "char": 70
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 132,
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
                                        "value": "property",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 132,
                                        "char": 54
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "properties",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 132,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "propertyName",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 132,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 132,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 132,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 132,
                                "char": 54
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "new",
                                        "class": "Collection",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 136,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 137,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 139,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "property",
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 139,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 140,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the annotations found in a specific property\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 122,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 122,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                        "line": 122,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                    "line": 121,
                    "last-line": 144,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getProperties",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 145,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "classAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 147,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 152,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "classAnnotations",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 152,
                                            "char": 37
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                    "line": 152,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 152,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 152,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 152,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 154,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "classAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 154,
                                    "char": 33
                                },
                                "name": "getPropertiesAnnotations",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 154,
                                "char": 60
                            },
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 155,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the annotations found in all the class' methods\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 146,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                        "line": 146,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                    "line": 145,
                    "last-line": 159,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReader",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 162,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "reader",
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 162,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 162,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 162,
                                    "char": 33
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 162,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 162,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "reader",
                                            "expr": {
                                                "type": "new",
                                                "class": "Reader",
                                                "dynamic": 0,
                                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                                "line": 163,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                            "line": 163,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 164,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 166,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 166,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "reader",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 166,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 166,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 167,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the annotation reader\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ReaderInterface",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 161,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 161,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                        "line": 161,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                    "line": 160,
                    "last-line": 171,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setReader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "reader",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ReaderInterface",
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                "line": 172,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 172,
                            "char": 55
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
                                    "property": "reader",
                                    "expr": {
                                        "type": "variable",
                                        "value": "reader",
                                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                        "line": 174,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                                    "line": 174,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                            "line": 175,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the annotations parser\n     *",
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
                    "line": 172,
                    "last-line": 176,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
            "line": 23,
            "char": 14
        },
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AbstractAdapter.zep",
        "line": 23,
        "char": 14
    }
]