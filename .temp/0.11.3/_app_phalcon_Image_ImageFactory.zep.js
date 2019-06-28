[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Image",
        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Config",
                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\AbstractFactory",
                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                "line": 14,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                "line": 15,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Image\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                "line": 16,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Image\/ImageFactory\n *",
        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
        "line": 21,
        "char": 5
    },
    {
        "type": "class",
        "name": "ImageFactory",
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
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 26,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 26,
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
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 28,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 28,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 28,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 28,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 29,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * TagFactory constructor.\n     *",
                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                    "line": 26,
                    "last-line": 33,
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
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 34,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "height",
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 36,
                                    "char": 19
                                },
                                {
                                    "variable": "file",
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 36,
                                    "char": 25
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 36,
                                    "char": 31
                                },
                                {
                                    "variable": "width",
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 36,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 38,
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
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 38,
                                            "char": 27
                                        },
                                        "name": "checkConfig",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "config",
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 38,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 38,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 38,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 38,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 40,
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
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 40,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "file",
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 40,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 40,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 40,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 40,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 40,
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
                                                    "value": "You must provide 'file' option in factory config parameter.",
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 43,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 43,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 43,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 44,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 46,
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
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 46,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "adapter",
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 46,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 46,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 46,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 48,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "variable",
                                    "value": "config",
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 48,
                                    "char": 21
                                },
                                "right": {
                                    "type": "string",
                                    "value": "adapter",
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 48,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 48,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 50,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "file",
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
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 50,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 50,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "file",
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 50,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 50,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 50,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 50,
                                    "char": 44
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "height",
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
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 51,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 51,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "height",
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 51,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 51,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 51,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 51,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 51,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 51,
                                    "char": 52
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "width",
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
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 52,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 52,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "width",
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 52,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 52,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 52,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 52,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 52,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 52,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 54,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 54,
                                    "char": 21
                                },
                                "name": "newInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 54,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 54,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "file",
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 54,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 54,
                                        "char": 44
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "width",
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 54,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 54,
                                        "char": 51
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "height",
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 54,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 54,
                                        "char": 59
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 54,
                                "char": 60
                            },
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 55,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Factory to create an instace from a Config object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 35,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 35,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                        "line": 35,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                    "line": 34,
                    "last-line": 59,
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
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 61,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "file",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 62,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "width",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 63,
                                "char": 25
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 63,
                            "char": 25
                        },
                        {
                            "type": "parameter",
                            "name": "height",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 65,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 65,
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
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 67,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 69,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 69,
                                    "char": 14
                                },
                                "name": "checkService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 69,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 69,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 69,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 71,
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
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 71,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "services",
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 71,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 71,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 71,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 71,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 71,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 71,
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
                                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                        "line": 72,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mapper",
                                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                        "line": 72,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 72,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 72,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 72,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 72,
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
                                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                    "line": 73,
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
                                                            "value": "file",
                                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                            "line": 73,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                        "line": 73,
                                                        "char": 61
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "width",
                                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                            "line": 73,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                        "line": 73,
                                                        "char": 68
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "height",
                                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                            "line": 73,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                        "line": 73,
                                                        "char": 76
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                                "line": 73,
                                                "char": 77
                                            },
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 73,
                                            "char": 77
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 74,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 76,
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
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 76,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 76,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 76,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 76,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 76,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 77,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Creates a new instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                    "line": 66,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 66,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                        "line": 66,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                    "line": 60,
                    "last-line": 79,
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
                                            "value": "gd",
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 82,
                                            "char": 21
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Image\\\\Adapter\\\\Gd",
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 82,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 82,
                                        "char": 52
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "imagick",
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 83,
                                            "char": 21
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Image\\\\Adapter\\\\Imagick",
                                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                            "line": 84,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                        "line": 84,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 84,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                            "line": 85,
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
                                "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                                "line": 80,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                        "line": 80,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
                    "line": 79,
                    "last-line": 86,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
            "line": 21,
            "char": 5
        },
        "file": "\/app\/phalcon\/Image\/ImageFactory.zep",
        "line": 21,
        "char": 5
    }
]