[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Annotations",
        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                "line": 13,
                "char": 48
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\AbstractFactory",
                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                "line": 14,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                "line": 15,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Factory to create annotations components\n *",
        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "AnnotationsFactory",
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
                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                "line": 25,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 25,
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
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 27,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 27,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 27,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                "line": 27,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 28,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * AdapterFactory constructor.\n     *",
                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                    "line": 25,
                    "last-line": 32,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "load",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "config",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 33,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 35,
                                    "char": 17
                                },
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 35,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 37,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "config",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 37,
                                            "char": 27
                                        },
                                        "name": "checkConfig",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "config",
                                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                    "line": 37,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                "line": 37,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 37,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 37,
                                    "char": 47
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 38,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "adapter",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 38,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 38,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 38,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 40,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "variable",
                                    "value": "config",
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 40,
                                    "char": 21
                                },
                                "right": {
                                    "type": "string",
                                    "value": "adapter",
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 40,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                "line": 40,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 42,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "options",
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
                                                    "value": "config",
                                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                    "line": 42,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                "line": 42,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                    "line": 42,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                "line": 42,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                    "line": 42,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                "line": 42,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 42,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 42,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 44,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 44,
                                    "char": 21
                                },
                                "name": "newInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 44,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 44,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 44,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 44,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                "line": 44,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 45,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Factory to create an instace from a Config object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                "line": 34,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                        "line": 34,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                    "line": 33,
                    "last-line": 49,
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
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 50,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                "line": 50,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 50,
                            "char": 66
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 52,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 54,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 54,
                                    "char": 14
                                },
                                "name": "checkService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 54,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 54,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                "line": 54,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 56,
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
                                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                "line": 56,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "services",
                                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                "line": 56,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 56,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 56,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 56,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 56,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                "line": 56,
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
                                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                        "line": 57,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mapper",
                                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                        "line": 57,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                    "line": 57,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                    "line": 57,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                "line": 57,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 57,
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
                                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                    "line": 58,
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
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                            "line": 58,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                        "line": 58,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                                "line": 58,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 58,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 59,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 61,
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
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 61,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 61,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 61,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 61,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                "line": 61,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 62,
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
                                    "value": "AbstractAdapter",
                                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                    "line": 51,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                "line": 51,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                        "line": 51,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                    "line": 50,
                    "last-line": 66,
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
                                            "value": "apcu",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 70,
                                            "char": 20
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Annotations\\\\Adapter\\\\Apcu",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 70,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 70,
                                        "char": 59
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "memory",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 71,
                                            "char": 20
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Annotations\\\\Adapter\\\\Memory",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 71,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 71,
                                        "char": 61
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "stream",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 72,
                                            "char": 20
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Annotations\\\\Adapter\\\\Stream",
                                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                            "line": 73,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                        "line": 73,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                "line": 73,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                            "line": 74,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * The available adapters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                                "line": 68,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                        "line": 68,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
                    "line": 67,
                    "last-line": 75,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Annotations\/AnnotationsFactory.zep",
        "line": 20,
        "char": 5
    }
]