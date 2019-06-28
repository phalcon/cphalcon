[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger",
        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Config",
                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                "line": 14,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Logger",
                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                "line": 15,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\AdapterFactory",
                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                "line": 16,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PhalconNG\\Logger\\LoggerFactory\n *\n * Logger factory\n *",
        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
        "line": 23,
        "char": 5
    },
    {
        "type": "class",
        "name": "LoggerFactory",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "adapterFactory",
                    "docblock": "**\n     * @var AdapterFactory\n     *",
                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                    "line": 30,
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
                            "name": "factory",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "AdapterFactory",
                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                "line": 30,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 30,
                            "char": 57
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
                                    "property": "adapterFactory",
                                    "expr": {
                                        "type": "variable",
                                        "value": "factory",
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 32,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 32,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 33,
                            "char": 5
                        }
                    ],
                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                    "line": 30,
                    "last-line": 37,
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
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 38,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "adapter",
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 40,
                                    "char": 20
                                },
                                {
                                    "variable": "adapterClass",
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 40,
                                    "char": 34
                                },
                                {
                                    "variable": "adapterFileName",
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 40,
                                    "char": 51
                                },
                                {
                                    "variable": "adapterOptions",
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 40,
                                    "char": 67
                                },
                                {
                                    "variable": "adapters",
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 41,
                                    "char": 21
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 41,
                                    "char": 27
                                },
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 41,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 42,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 42,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 44,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 44,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 44,
                                        "char": 27
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 44,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 44,
                                    "char": 37
                                },
                                "right": {
                                    "type": "instanceof",
                                    "left": {
                                        "type": "variable",
                                        "value": "config",
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 44,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "Config",
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 44,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 44,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                "line": 44,
                                "char": 64
                            },
                            "statements": [
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
                                                    "value": "config",
                                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                    "line": 45,
                                                    "char": 33
                                                },
                                                "name": "toArray",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 45,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 45,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 46,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 48,
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
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 48,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 48,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 48,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 48,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                "line": 48,
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
                                                    "value": "Config must be array or Phalcon\\\\Config object",
                                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                    "line": 51,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 51,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 51,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 52,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 54,
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
                                                "value": "config",
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 54,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 54,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 54,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 54,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 54,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                "line": 54,
                                "char": 41
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
                                                    "value": "You must provide 'name' option in factory config parameter.",
                                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                    "line": 57,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 57,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 57,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 58,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 60,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 60,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 60,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 60,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 60,
                                    "char": 36
                                },
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
                                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                    "line": 61,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 61,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                    "line": 61,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 61,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                    "line": 61,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 61,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 61,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 61,
                                    "char": 53
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "adapters",
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
                                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                    "line": 62,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 62,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "adapters",
                                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                    "line": 62,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 62,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                    "line": 62,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 62,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 62,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 62,
                                    "char": 54
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 63,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 63,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 65,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "adapters",
                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                "line": 65,
                                "char": 33
                            },
                            "value": "adapter",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "adapterClass",
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
                                                            "value": "adapter",
                                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                            "line": 66,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                        "line": 66,
                                                        "char": 51
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "adapter",
                                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                            "line": 66,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                        "line": 66,
                                                        "char": 60
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 66,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 66,
                                            "char": 61
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "adapterFileName",
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
                                                            "value": "adapter",
                                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                            "line": 67,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                        "line": 67,
                                                        "char": 51
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                            "line": 67,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                        "line": 67,
                                                        "char": 57
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 67,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 67,
                                            "char": 58
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "adapterOptions",
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
                                                            "value": "adapter",
                                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                            "line": 68,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                        "line": 68,
                                                        "char": 51
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                            "line": 68,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                        "line": 68,
                                                        "char": 60
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "empty-array",
                                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                            "line": 68,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                        "line": 68,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 68,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 68,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 70,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "data",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                        "line": 70,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "adapterFactory",
                                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                        "line": 70,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                    "line": 70,
                                                    "char": 47
                                                },
                                                "name": "newInstance",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "adapterClass",
                                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                            "line": 71,
                                                            "char": 29
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                        "line": 71,
                                                        "char": 29
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "adapterFileName",
                                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                            "line": 72,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                        "line": 72,
                                                        "char": 32
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "adapterOptions",
                                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                            "line": 74,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                        "line": 74,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                                "line": 74,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 74,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 75,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
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
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 77,
                                    "char": 21
                                },
                                "name": "newInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 77,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 77,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 77,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 77,
                                        "char": 44
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                "line": 77,
                                "char": 45
                            },
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 78,
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
                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                "line": 39,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                        "line": 39,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                    "line": 38,
                    "last-line": 87,
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
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 88,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "adapters",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                "line": 88,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 88,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "Logger",
                                "dynamic": 0,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 90,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 90,
                                        "char": 31
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "adapters",
                                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                            "line": 90,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                        "line": 90,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                "line": 90,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                            "line": 91,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a Logger object\n     *\n     * @param string $name\n     * @param array  $adapters\n     *\n     * @return Logger\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Logger",
                                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                    "line": 89,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                                "line": 89,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                        "line": 89,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
                    "line": 88,
                    "last-line": 92,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
            "line": 23,
            "char": 5
        },
        "file": "\/app\/phalcon\/Logger\/LoggerFactory.zep",
        "line": 23,
        "char": 5
    }
]