[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Paginator\\Adapter",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\Repository",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                "line": 13,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\RepositoryInterface",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                "line": 14,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Paginator\\Adapter\\AbstractAdapter\n *",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
        "line": 19,
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
                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                "line": 20,
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
                    "name": "config",
                    "docblock": "**\n     * Configuration of paginator\n     *",
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                    "line": 28,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "limitRows",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                        "line": 29,
                        "char": 31
                    },
                    "docblock": "**\n     * Number of rows to show in the paginator. By default is null\n     *",
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                    "line": 33,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "page",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                        "line": 34,
                        "char": 26
                    },
                    "docblock": "**\n     * Current page in paginate\n     *",
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                    "line": 40,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "repository",
                    "docblock": "**\n     * Repository for pagination\n     *\n     * @var RepositoryInterface\n     *",
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                    "line": 45,
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
                            "name": "config",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 46,
                            "char": 46
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
                                    "property": "config",
                                    "expr": {
                                        "type": "variable",
                                        "value": "config",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 48,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 48,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 50,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "config",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 50,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "limit",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 50,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 50,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 50,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                            "line": 51,
                                            "char": 18
                                        },
                                        "name": "setLimit",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "config",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                        "line": 52,
                                                        "char": 23
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "limit",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                        "line": 52,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                    "line": 53,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                "line": 53,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 53,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 54,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 56,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "config",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 56,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "page",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 56,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 56,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 56,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                            "line": 57,
                                            "char": 18
                                        },
                                        "name": "setCurrentPage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "config",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                        "line": 58,
                                                        "char": 23
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "page",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                        "line": 58,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                    "line": 59,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                "line": 59,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 59,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 60,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 62,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "config",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 62,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "repository",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 62,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 62,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 62,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                            "line": 63,
                                            "char": 18
                                        },
                                        "name": "setRepository",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "config",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                        "line": 64,
                                                        "char": 23
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "repository",
                                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                        "line": 64,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                    "line": 65,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                "line": 65,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 65,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 66,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 67,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Paginator\\Adapter\\AbstractAdapter constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                        "line": 47,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                    "line": 46,
                    "last-line": 71,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLimit",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 74,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "limitRows",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 74,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 74,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 75,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get current rows limit\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 73,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                        "line": 73,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                    "line": 72,
                    "last-line": 79,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setCurrentPage",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "page",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 80,
                            "char": 44
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
                                    "property": "page",
                                    "expr": {
                                        "type": "variable",
                                        "value": "page",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 82,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 82,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 84,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 84,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 85,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the current page number\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 81,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 81,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                        "line": 81,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                    "line": 80,
                    "last-line": 89,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setLimit",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "limitRows",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 90,
                            "char": 43
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
                                    "property": "limitRows",
                                    "expr": {
                                        "type": "variable",
                                        "value": "limitRows",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 92,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 92,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 94,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 94,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 95,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set current rows limit\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 91,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 91,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                        "line": 91,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                    "line": 90,
                    "last-line": 99,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRepository",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "repository",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "RepositoryInterface",
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 100,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 100,
                            "char": 67
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
                                    "property": "repository",
                                    "expr": {
                                        "type": "variable",
                                        "value": "repository",
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 102,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 102,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 104,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 104,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 105,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets current repository for pagination\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Adapter",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 101,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 101,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                        "line": 101,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                    "line": 100,
                    "last-line": 109,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getRepository",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "properties",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 110,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 110,
                            "char": 61
                        }
                    ],
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
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                            "line": 112,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "repository",
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                            "line": 112,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 112,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 112,
                                    "char": 37
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 112,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 112,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "repository",
                                            "expr": {
                                                "type": "new",
                                                "class": "Repository",
                                                "dynamic": 0,
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                "line": 113,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                            "line": 113,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 114,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 116,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "properties",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 116,
                                    "char": 25
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 116,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 116,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                "line": 117,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "repository",
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                "line": 117,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                            "line": 117,
                                            "char": 30
                                        },
                                        "name": "setProperties",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "properties",
                                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                    "line": 117,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                                "line": 117,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                        "line": 117,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 118,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 120,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 120,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "repository",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 120,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 120,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                            "line": 121,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets current repository for pagination\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RepositoryInterface",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                    "line": 111,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                                "line": 111,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                        "line": 111,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
                    "line": 110,
                    "last-line": 122,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
            "line": 19,
            "char": 14
        },
        "file": "\/app\/phalcon\/Paginator\/Adapter\/AbstractAdapter.zep",
        "line": 19,
        "char": 14
    }
]