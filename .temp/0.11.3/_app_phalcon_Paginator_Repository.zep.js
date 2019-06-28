[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Paginator",
        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Paginator\\Repository\n *\n * Repository of current state Phalcon\\Paginator\\AdapterInterface::paginate()\n *",
        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Repository",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "RepositoryInterface",
                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                "line": 21,
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
                    "name": "aliases",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 25,
                        "char": 27
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 29,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "properties",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 30,
                        "char": 30
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 34,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "property",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 35,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "method",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 37,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 39,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "method",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "get",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 39,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "camelize",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                            "line": 40,
                                                            "char": 18
                                                        },
                                                        "name": "getRealNameProperty",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "property",
                                                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                                    "line": 40,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                                "line": 40,
                                                                "char": 47
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                        "line": 41,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                    "line": 41,
                                                    "char": 9
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 41,
                                            "char": 10
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 41,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 41,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 43,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "method_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 43,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 43,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "method",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 43,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 43,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 43,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 44,
                                            "char": 25
                                        },
                                        "name": "method",
                                        "call-type": 2,
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 44,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 45,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 50,
                            "char": 21
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "trigger_error",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "Access to undefined property ",
                                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                        "line": 51,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "fcall",
                                                        "name": "get_class",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                                    "line": 51,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                                "line": 51,
                                                                "char": 59
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                        "line": 51,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                    "line": 51,
                                                    "char": 61
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "::",
                                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                    "line": 51,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 51,
                                                "char": 66
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "property",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 52,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 52,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 52,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 52,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 54,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 54,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 55,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 35,
                                "char": 51
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 36,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 36,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 35,
                    "last-line": 59,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAliases",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 62,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "aliases",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 62,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 62,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 63,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 61,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 61,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 60,
                    "last-line": 67,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCurrent",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 70,
                                    "char": 21
                                },
                                "name": "getProperty",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 70,
                                                "char": 61
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "PROPERTY_CURRENT_PAGE",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 70,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 70,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 70,
                                        "char": 61
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 70,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 70,
                                        "char": 64
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 70,
                                "char": 65
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 71,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 69,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 69,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 68,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFirst",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 78,
                                    "char": 21
                                },
                                "name": "getProperty",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 78,
                                                "char": 59
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "PROPERTY_FIRST_PAGE",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 78,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 78,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 78,
                                        "char": 59
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 78,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 78,
                                        "char": 62
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 78,
                                "char": 63
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 79,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 77,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 77,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 76,
                    "last-line": 83,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getItems",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 86,
                                    "char": 21
                                },
                                "name": "getProperty",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 86,
                                                "char": 54
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "PROPERTY_ITEMS",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 86,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 86,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 86,
                                        "char": 54
                                    },
                                    {
                                        "parameter": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 86,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 86,
                                        "char": 60
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 86,
                                "char": 61
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 87,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 85,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 85,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 84,
                    "last-line": 91,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLast",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 94,
                                    "char": 21
                                },
                                "name": "getProperty",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 94,
                                                "char": 58
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "PROPERTY_LAST_PAGE",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 94,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 94,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 94,
                                        "char": 58
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 94,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 94,
                                        "char": 61
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 94,
                                "char": 62
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 95,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 93,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 93,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 92,
                    "last-line": 99,
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
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 102,
                                    "char": 21
                                },
                                "name": "getProperty",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 102,
                                                "char": 54
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "PROPERTY_LIMIT",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 102,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 102,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 102,
                                        "char": 54
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 102,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 102,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 102,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 103,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 101,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 101,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 100,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNext",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 110,
                                    "char": 21
                                },
                                "name": "getProperty",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 110,
                                                "char": 58
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "PROPERTY_NEXT_PAGE",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 110,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 110,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 110,
                                        "char": 58
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 110,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 110,
                                        "char": 61
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 110,
                                "char": 62
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 111,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 109,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 109,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 108,
                    "last-line": 115,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPrevious",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 118,
                                    "char": 21
                                },
                                "name": "getProperty",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 118,
                                                "char": 62
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "PROPERTY_PREVIOUS_PAGE",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 118,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 118,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 118,
                                        "char": 62
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 118,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 118,
                                        "char": 65
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 118,
                                "char": 66
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 119,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 117,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 117,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 116,
                    "last-line": 123,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTotalItems",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 126,
                                    "char": 21
                                },
                                "name": "getProperty",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 126,
                                                "char": 60
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "PROPERTY_TOTAL_ITEMS",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 126,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 126,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 126,
                                        "char": 60
                                    },
                                    {
                                        "parameter": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 126,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 126,
                                        "char": 63
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 126,
                                "char": 64
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 127,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 125,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 125,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 124,
                    "last-line": 131,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAliases",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "aliases",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 132,
                            "char": 45
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
                                    "property": "aliases",
                                    "expr": {
                                        "type": "variable",
                                        "value": "aliases",
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 134,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 134,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 136,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 136,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 137,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RepositoryInterface",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 133,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 133,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 133,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 132,
                    "last-line": 141,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setProperties",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "properties",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 142,
                            "char": 51
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
                                    "property": "properties",
                                    "expr": {
                                        "type": "variable",
                                        "value": "properties",
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 144,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 144,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 146,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 146,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 147,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * {@inheritdoc}\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RepositoryInterface",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 143,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 143,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 143,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 142,
                    "last-line": 151,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getProperty",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "property",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 152,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 152,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 152,
                            "char": 76
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Arr",
                                "dynamic": 0,
                                "name": "get",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 155,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "properties",
                                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                                "line": 155,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 155,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 155,
                                        "char": 29
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "property",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 156,
                                            "char": 21
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 156,
                                        "char": 21
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "defaultValue",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 158,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 158,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 158,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 159,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets value of property by name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 153,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 153,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 152,
                    "last-line": 163,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getRealNameProperty",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "property",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 164,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "aliases",
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 166,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 168,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "aliases",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 168,
                                            "char": 28
                                        },
                                        "name": "getAliases",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 168,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 168,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 170,
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
                                        "value": "aliases",
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 170,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "property",
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 170,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 170,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 170,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "aliases",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 171,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "property",
                                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                            "line": 171,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                        "line": 171,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                    "line": 172,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 174,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "property",
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 174,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                            "line": 175,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolve alias property name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                                "line": 165,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                        "line": 165,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Paginator\/Repository.zep",
                    "line": 164,
                    "last-line": 176,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Paginator\/Repository.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Paginator\/Repository.zep",
        "line": 20,
        "char": 5
    }
]