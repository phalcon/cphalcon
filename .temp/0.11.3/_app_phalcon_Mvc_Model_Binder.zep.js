[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Closure",
                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                "line": 13,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Controller\\BindModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                "line": 14,
                "char": 46
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Binder\\BindableInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                "line": 15,
                "char": 47
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                "line": 16,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ReflectionFunction",
                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                "line": 17,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ReflectionMethod",
                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                "line": 18,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Binding\n *\n * This is an class for binding models into params for handler\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
        "line": 25,
        "char": 5
    },
    {
        "type": "class",
        "name": "Binder",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "BinderInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                "line": 26,
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
                    "name": "boundModels",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                        "line": 32,
                        "char": 32
                    },
                    "docblock": "**\n     * Array for storing active bound models\n     *\n     * @var array\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 32,
                            "char": 38
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                    "line": 36,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "cache",
                    "docblock": "**\n     * Cache object used for caching parameters for model binding\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                    "line": 41,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "internalCache",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                        "line": 42,
                        "char": 33
                    },
                    "docblock": "**\n     * Internal cache for caching parameters for model binding during request\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                    "line": 46,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "originalValues",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                        "line": 47,
                        "char": 35
                    },
                    "docblock": "**\n     * Array for original values\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 47,
                            "char": 41
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                    "line": 51,
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
                            "name": "cache",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 52,
                                "char": 56
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 52,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 52,
                            "char": 64
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
                                    "property": "cache",
                                    "expr": {
                                        "type": "variable",
                                        "value": "cache",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 54,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 54,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 55,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\Binder constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                        "line": 53,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                    "line": 52,
                    "last-line": 59,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "bindToHandler",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "object",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 60,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 60,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "cacheKey",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 60,
                            "char": 80
                        },
                        {
                            "type": "parameter",
                            "name": "methodName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 60,
                                "char": 107
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 60,
                            "char": 107
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "paramKey",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 62,
                                    "char": 21
                                },
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 62,
                                    "char": 32
                                },
                                {
                                    "variable": "boundModel",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 62,
                                    "char": 44
                                },
                                {
                                    "variable": "paramsCache",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 62,
                                    "char": 57
                                },
                                {
                                    "variable": "paramValue",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 62,
                                    "char": 69
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 64,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "originalValues",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 64,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 64,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 66,
                            "char": 10
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
                                            "type": "not",
                                            "left": {
                                                "type": "list",
                                                "left": {
                                                    "type": "instanceof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "handler",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 66,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "Closure",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 66,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 66,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 66,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 66,
                                            "char": 53
                                        },
                                        "right": {
                                            "type": "identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "methodName",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 66,
                                                "char": 68
                                            },
                                            "right": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 66,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 66,
                                            "char": 74
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 66,
                                        "char": 74
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 66,
                                    "char": 76
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 66,
                                "char": 76
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
                                                    "value": "You must specify methodName for handler or pass Closure as handler",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 69,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 69,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 69,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 70,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 72,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "boundModels",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 72,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 72,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 73,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "paramsCache",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 73,
                                            "char": 32
                                        },
                                        "name": "getParamsFromCache",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cacheKey",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 73,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 73,
                                                "char": 60
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 73,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 73,
                                    "char": 61
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 75,
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
                                        "value": "paramsCache",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 75,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 75,
                                    "char": 32
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 75,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 75,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "paramsCache",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 76,
                                        "char": 52
                                    },
                                    "key": "paramKey",
                                    "value": "className",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "paramValue",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 77,
                                                            "char": 40
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "paramKey",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 77,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 77,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 77,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 78,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "boundModel",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 78,
                                                            "char": 39
                                                        },
                                                        "name": "findBoundModel",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "paramValue",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 78,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                "line": 78,
                                                                "char": 65
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "className",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 78,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                "line": 78,
                                                                "char": 76
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 78,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 78,
                                                    "char": 77
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 79,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "originalValues",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "paramKey",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 79,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "paramValue",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 79,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 79,
                                                    "char": 64
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 80,
                                            "char": 19
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
                                                            "type": "variable",
                                                            "value": "paramKey",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 80,
                                                            "char": 36
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "boundModel",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 80,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 80,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 81,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "boundModels",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "paramKey",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 81,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "boundModel",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 81,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 81,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 82,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 84,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 84,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 85,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 87,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 87,
                                    "char": 21
                                },
                                "name": "getParamsFromReflection",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 88,
                                            "char": 20
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 88,
                                        "char": 20
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 89,
                                            "char": 19
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 89,
                                        "char": 19
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cacheKey",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 90,
                                            "char": 21
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 90,
                                        "char": 21
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "methodName",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 92,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 92,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 92,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 93,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Bind models into params in proper handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 61,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                        "line": 61,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                    "line": 60,
                    "last-line": 97,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "findBoundModel",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "paramValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 98,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 98,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 1,
                                "class": "className",
                                "dynamic": 0,
                                "name": "findFirst",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "paramValue",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 100,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 100,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 100,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 101,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Find the model by param value.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 98,
                                "char": 83
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 99,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                        "line": 99,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                    "line": 98,
                    "last-line": 105,
                    "char": 22
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCache",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 108,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "cache",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 108,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 108,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 109,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets cache instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 107,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 107,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                        "line": 107,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                    "line": 106,
                    "last-line": 113,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getParamsFromCache",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cacheKey",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 114,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "cache",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 116,
                                    "char": 18
                                },
                                {
                                    "variable": "internalParams",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 116,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 118,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "internalParams",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 118,
                                    "char": 64
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 118,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "internalCache",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 118,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 118,
                                        "char": 53
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "cacheKey",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 118,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 118,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 118,
                                "char": 64
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "internalParams",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 119,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 120,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 122,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cache",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 122,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "cache",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 122,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 122,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 122,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 124,
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
                                        "value": "cache",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 124,
                                        "char": 20
                                    },
                                    "right": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 124,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 124,
                                    "char": 28
                                },
                                "right": {
                                    "type": "not",
                                    "left": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cache",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 124,
                                            "char": 37
                                        },
                                        "name": "exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cacheKey",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 124,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 124,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 124,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 124,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 124,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 125,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 126,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 128,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "internalParams",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cache",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 128,
                                            "char": 36
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cacheKey",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 128,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 128,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 128,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 128,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 129,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "internalCache",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "cacheKey",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 129,
                                            "char": 41
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "internalParams",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 129,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 129,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 131,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "internalParams",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 131,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 132,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get params classes from cache by key\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 114,
                                "char": 69
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 115,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                        "line": 115,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                    "line": 114,
                    "last-line": 136,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getParamsFromReflection",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "object",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 137,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 137,
                            "char": 76
                        },
                        {
                            "type": "parameter",
                            "name": "cacheKey",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 137,
                            "char": 93
                        },
                        {
                            "type": "parameter",
                            "name": "methodName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 137,
                            "char": 113
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "methodParams",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 139,
                                    "char": 25
                                },
                                {
                                    "variable": "reflection",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 139,
                                    "char": 37
                                },
                                {
                                    "variable": "paramKey",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 139,
                                    "char": 47
                                },
                                {
                                    "variable": "methodParam",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 139,
                                    "char": 60
                                },
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 139,
                                    "char": 71
                                },
                                {
                                    "variable": "realClasses",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 140,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 140,
                                    "char": 31
                                },
                                {
                                    "variable": "boundModel",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 140,
                                    "char": 43
                                },
                                {
                                    "variable": "cache",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 140,
                                    "char": 50
                                },
                                {
                                    "variable": "handlerClass",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 140,
                                    "char": 64
                                },
                                {
                                    "variable": "reflectionClass",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 141,
                                    "char": 28
                                },
                                {
                                    "variable": "paramsKeys",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 141,
                                    "char": 40
                                },
                                {
                                    "variable": "paramValue",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 141,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 142,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "paramsCache",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 142,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 144,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "paramsCache",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 144,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 144,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 146,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "methodName",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 146,
                                    "char": 24
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 146,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 146,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "reflection",
                                            "expr": {
                                                "type": "new",
                                                "class": "ReflectionMethod",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "handler",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 147,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 147,
                                                        "char": 58
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "methodName",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 147,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 147,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 147,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 147,
                                            "char": 71
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 148,
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
                                            "variable": "reflection",
                                            "expr": {
                                                "type": "new",
                                                "class": "ReflectionFunction",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "handler",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 149,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 149,
                                                        "char": 60
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 149,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 149,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 150,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 152,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cache",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 152,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "cache",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 152,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 152,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 152,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 154,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "methodParams",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 154,
                                            "char": 39
                                        },
                                        "name": "getParameters",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 154,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 154,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 155,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "paramsKeys",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_keys",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 155,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 155,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 155,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 155,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 157,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "methodParams",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 157,
                                "char": 51
                            },
                            "key": "paramKey",
                            "value": "methodParam",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "reflectionClass",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "methodParam",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 158,
                                                    "char": 47
                                                },
                                                "name": "getClass",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 158,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 158,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 160,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "reflectionClass",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 160,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 160,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 162,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 164,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "className",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "reflectionClass",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 164,
                                                    "char": 45
                                                },
                                                "name": "getName",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 164,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 164,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 166,
                                    "char": 14
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
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 166,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "paramKey",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 166,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 166,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 166,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 166,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "paramKey",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "paramsKeys",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 167,
                                                            "char": 42
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "paramKey",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 167,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 167,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 167,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 168,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 170,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "boundModel",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 170,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 170,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 171,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "paramValue",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 171,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "paramKey",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 171,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 171,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 171,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 173,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "className",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 173,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "Phalcon\\\\Mvc\\\\Model",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 173,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 173,
                                        "char": 49
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "realClasses",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 174,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 174,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 174,
                                                "char": 40
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "instanceof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "handler",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 175,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "BindModelInterface",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 175,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 175,
                                                        "char": 62
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "handlerClass",
                                                                    "expr": {
                                                                        "type": "fcall",
                                                                        "name": "get_class",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "handler",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                                    "line": 176,
                                                                                    "char": 61
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                                "line": 176,
                                                                                "char": 61
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                        "line": 176,
                                                                        "char": 62
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 176,
                                                                    "char": 62
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 177,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "realClasses",
                                                                    "expr": {
                                                                        "type": "scall",
                                                                        "dynamic-class": 1,
                                                                        "class": "handlerClass",
                                                                        "dynamic": 0,
                                                                        "name": "getModelName",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                        "line": 177,
                                                                        "char": 73
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 177,
                                                                    "char": 73
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 178,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "elseif_statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "instanceof",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "handler",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 178,
                                                                    "char": 47
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BindableInterface",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 178,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                "line": 178,
                                                                "char": 67
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "variable",
                                                                            "operator": "assign",
                                                                            "variable": "realClasses",
                                                                            "expr": {
                                                                                "type": "mcall",
                                                                                "variable": {
                                                                                    "type": "variable",
                                                                                    "value": "handler",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                                    "line": 179,
                                                                                    "char": 51
                                                                                },
                                                                                "name": "getModelName",
                                                                                "call-type": 1,
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                                "line": 179,
                                                                                "char": 66
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                            "line": 179,
                                                                            "char": 66
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 180,
                                                                    "char": 21
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 180,
                                                            "char": 26
                                                        }
                                                    ],
                                                    "else_statements": [
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
                                                                            "value": "Handler must implement Phalcon\\\\Mvc\\\\Model\\\\Binder\\\\BindableInterface in order to use Phalcon\\\\Mvc\\\\Model as parameter",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                            "line": 183,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                        "line": 183,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                "line": 183,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 184,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 185,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 187,
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
                                                        "value": "realClasses",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 187,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 187,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 187,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 187,
                                                "char": 48
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
                                                                    "value": "className",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 188,
                                                                    "char": 73
                                                                },
                                                                "right": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "realClasses",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                        "line": 188,
                                                                        "char": 62
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "paramKey",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                        "line": 188,
                                                                        "char": 71
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 188,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                "line": 188,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 188,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 188,
                                                        "char": 73
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
                                                                                    "value": "You should provide model class name for ",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                                    "line": 190,
                                                                                    "char": 70
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "paramKey",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                                    "line": 190,
                                                                                    "char": 81
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                                "line": 190,
                                                                                "char": 81
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": " parameter",
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                                "line": 191,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                            "line": 191,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                        "line": 191,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                "line": 191,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 192,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 194,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "boundModel",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 194,
                                                                    "char": 43
                                                                },
                                                                "name": "findBoundModel",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "paramValue",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                            "line": 194,
                                                                            "char": 69
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                        "line": 194,
                                                                        "char": 69
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "className",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                            "line": 194,
                                                                            "char": 80
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                        "line": 194,
                                                                        "char": 80
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                "line": 194,
                                                                "char": 81
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 194,
                                                            "char": 81
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 195,
                                                    "char": 17
                                                }
                                            ],
                                            "elseif_statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "typeof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "realClasses",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                "line": 195,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 195,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "string",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 195,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 195,
                                                        "char": 55
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "className",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "realClasses",
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                        "line": 196,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 196,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 197,
                                                            "char": 23
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "boundModel",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                            "line": 197,
                                                                            "char": 43
                                                                        },
                                                                        "name": "findBoundModel",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "paramValue",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                                    "line": 197,
                                                                                    "char": 69
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                                "line": 197,
                                                                                "char": 69
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "className",
                                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                                    "line": 197,
                                                                                    "char": 80
                                                                                },
                                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                                "line": 197,
                                                                                "char": 80
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                        "line": 197,
                                                                        "char": 81
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 197,
                                                                    "char": 81
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 198,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 198,
                                                    "char": 22
                                                }
                                            ],
                                            "else_statements": [
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
                                                                    "value": "getModelName should return array or string",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 201,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                "line": 201,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 201,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 202,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 203,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "is_subclass_of",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "className",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 203,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 203,
                                                        "char": 46
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "Phalcon\\\\Mvc\\\\Model",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 203,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 203,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 203,
                                                "char": 69
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "boundModel",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                    "line": 204,
                                                                    "char": 39
                                                                },
                                                                "name": "findBoundModel",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "paramValue",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                            "line": 204,
                                                                            "char": 65
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                        "line": 204,
                                                                        "char": 65
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "className",
                                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                            "line": 204,
                                                                            "char": 76
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                        "line": 204,
                                                                        "char": 76
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                                "line": 204,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 204,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 205,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 207,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 207,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "boundModel",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 207,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 207,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 207,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "originalValues",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "paramKey",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 208,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "paramValue",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 208,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 208,
                                                    "char": 64
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 209,
                                            "char": 19
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
                                                            "type": "variable",
                                                            "value": "paramKey",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 209,
                                                            "char": 36
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "boundModel",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 209,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 209,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 210,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "boundModels",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "paramKey",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 210,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "boundModel",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 210,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 210,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 211,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "paramsCache",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "paramKey",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                            "line": 211,
                                                            "char": 41
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "className",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                        "line": 211,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 211,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 212,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 213,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 215,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "cache",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 215,
                                    "char": 19
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 215,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 215,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "cache",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 216,
                                            "char": 19
                                        },
                                        "name": "save",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cacheKey",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 216,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 216,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "paramsCache",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                    "line": 216,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                                "line": 216,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 216,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 217,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 219,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "internalCache",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "cacheKey",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                            "line": 219,
                                            "char": 41
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "paramsCache",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 219,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 219,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 221,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "params",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 221,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 222,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get modified params for handler using reflection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 138,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                        "line": 138,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                    "line": 137,
                    "last-line": 226,
                    "char": 22
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setCache",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "cache",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 227,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 227,
                            "char": 54
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
                                    "property": "cache",
                                    "expr": {
                                        "type": "variable",
                                        "value": "cache",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                        "line": 229,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 229,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 231,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 231,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                            "line": 232,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets cache instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "BinderInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                    "line": 228,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                                "line": 228,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                        "line": 228,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
                    "line": 227,
                    "last-line": 233,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
            "line": 25,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Binder.zep",
        "line": 25,
        "char": 5
    }
]