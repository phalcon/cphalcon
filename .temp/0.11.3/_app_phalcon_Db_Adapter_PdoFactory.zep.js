[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db\\Adapter",
        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Adapter\\AbstractAdapter",
                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                "line": 13,
                "char": 48
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\AbstractFactory",
                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                "line": 14,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                "line": 15,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
        "line": 17,
        "char": 5
    },
    {
        "type": "class",
        "name": "PdoFactory",
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                "line": 22,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 22,
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
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 24,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 24,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 24,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                "line": 24,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 25,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor\n     *",
                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                    "line": 22,
                    "last-line": 29,
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
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 30,
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
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 32,
                                    "char": 17
                                },
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 32,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 34,
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
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 34,
                                            "char": 27
                                        },
                                        "name": "checkConfig",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "config",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                    "line": 34,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                "line": 34,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 34,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 34,
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
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 35,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "adapter",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 35,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 35,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 35,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 37,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "variable",
                                    "value": "config",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 37,
                                    "char": 21
                                },
                                "right": {
                                    "type": "string",
                                    "value": "adapter",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 37,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                "line": 37,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 39,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                    "line": 39,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                "line": 39,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                    "line": 39,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                "line": 39,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                    "line": 39,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                "line": 39,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 39,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 39,
                                    "char": 52
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 41,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 41,
                                    "char": 21
                                },
                                "name": "newInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 41,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 41,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 41,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 41,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                "line": 41,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 42,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                "line": 31,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                        "line": 31,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                    "line": 30,
                    "last-line": 46,
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
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 47,
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
                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                "line": 47,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 47,
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
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 49,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 51,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 51,
                                    "char": 14
                                },
                                "name": "checkService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 51,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 51,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                "line": 51,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 53,
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
                                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                "line": 53,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "services",
                                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                "line": 53,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 53,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 53,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 53,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 53,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                "line": 53,
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
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                        "line": 54,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mapper",
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                        "line": 54,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                    "line": 54,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                    "line": 54,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                "line": 54,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 54,
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
                                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                    "line": 55,
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
                                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                            "line": 55,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                        "line": 55,
                                                        "char": 64
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                                "line": 55,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 55,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 56,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 58,
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
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 58,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 58,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 58,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 58,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                "line": 58,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 59,
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
                                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                    "line": 48,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                "line": 48,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                        "line": 48,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                    "line": 47,
                    "last-line": 63,
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
                                            "value": "mysql",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 67,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Db\\\\Adapter\\\\Pdo\\\\Mysql",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 67,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 67,
                                        "char": 60
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "postgresql",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 68,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Db\\\\Adapter\\\\Pdo\\\\Postgresql",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 68,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 68,
                                        "char": 65
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "sqlite",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 69,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Db\\\\Adapter\\\\Pdo\\\\Sqlite",
                                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                            "line": 70,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                        "line": 70,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                "line": 70,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                            "line": 71,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the available adapters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                                "line": 65,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                        "line": 65,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
                    "line": 64,
                    "last-line": 72,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
            "line": 17,
            "char": 5
        },
        "file": "\/app\/phalcon\/Db\/Adapter\/PdoFactory.zep",
        "line": 17,
        "char": 5
    }
]