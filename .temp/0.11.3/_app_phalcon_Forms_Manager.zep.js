[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Forms\/Manager.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Forms",
        "file": "\/app\/phalcon\/Forms\/Manager.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Forms Manager\n *",
        "file": "\/app\/phalcon\/Forms\/Manager.zep",
        "line": 16,
        "char": 5
    },
    {
        "type": "class",
        "name": "Manager",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "forms",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                        "line": 18,
                        "char": 25
                    },
                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                    "line": 24,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "create",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 25,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "entity",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                "line": 25,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 25,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "form",
                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                    "line": 27,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 29,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "form",
                                    "expr": {
                                        "type": "new",
                                        "class": "Form",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "entity",
                                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                                    "line": 29,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                                "line": 29,
                                                "char": 35
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                        "line": 29,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                    "line": 29,
                                    "char": 36
                                },
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "forms",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                            "line": 30,
                                            "char": 29
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "form",
                                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                        "line": 30,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                    "line": 30,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 32,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "form",
                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                "line": 32,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 33,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Creates a form registering it in the forms manager\n     *\n     * @param object entity\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Form",
                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                    "line": 26,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                "line": 26,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                        "line": 26,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                    "line": 25,
                    "last-line": 37,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
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
                                    "variable": "form",
                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                    "line": 40,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 42,
                            "char": 10
                        },
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
                                            "value": "form",
                                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                            "line": 42,
                                            "char": 52
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                                    "line": 42,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "forms",
                                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                                    "line": 42,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                                "line": 42,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                                "line": 42,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                            "line": 42,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                        "line": 42,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                    "line": 42,
                                    "char": 52
                                },
                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                "line": 42,
                                "char": 52
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
                                                            "value": "There is no form with name='",
                                                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                                            "line": 43,
                                                            "char": 62
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                                            "line": 43,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                                        "line": 43,
                                                        "char": 69
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "'",
                                                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                                        "line": 43,
                                                        "char": 72
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                                    "line": 43,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                                "line": 43,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                        "line": 43,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                    "line": 44,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 46,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "form",
                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                "line": 46,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 47,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a form by its name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Form",
                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                    "line": 39,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                "line": 39,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                        "line": 39,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                    "line": 38,
                    "last-line": 51,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "has",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 52,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                            "line": 54,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "forms",
                                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                            "line": 54,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                        "line": 54,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                        "line": 54,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                    "line": 54,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                "line": 54,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 55,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a form is registered in the forms manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                "line": 53,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                        "line": 53,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                    "line": 52,
                    "last-line": 59,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "set",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 60,
                            "char": 36
                        },
                        {
                            "type": "parameter",
                            "name": "form",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Form",
                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                "line": 60,
                                "char": 48
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 60,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "forms",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                            "line": 62,
                                            "char": 29
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "form",
                                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                        "line": 62,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                    "line": 62,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 64,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                "line": 64,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Manager.zep",
                            "line": 65,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Registers a form in the Forms Manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "FormManager",
                                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                    "line": 61,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Manager.zep",
                                "line": 61,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Manager.zep",
                        "line": 61,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Manager.zep",
                    "line": 60,
                    "last-line": 66,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Forms\/Manager.zep",
            "line": 16,
            "char": 5
        },
        "file": "\/app\/phalcon\/Forms\/Manager.zep",
        "line": 16,
        "char": 5
    }
]