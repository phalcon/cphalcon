[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Filter\/Filter.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Filter",
        "file": "\/app\/phalcon\/Filter\/Filter.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Closure",
                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                "line": 13,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Filter\/Filter.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Filter\\Exception",
                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                "line": 14,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Filter\/Filter.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Filter\\FilterInterface",
                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                "line": 15,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Filter\/Filter.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Lazy loads, stores and exposes sanitizer objects\n *",
        "file": "\/app\/phalcon\/Filter\/Filter.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Filter",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "FilterInterface",
                "file": "\/app\/phalcon\/Filter\/Filter.zep",
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
                    "name": "mapper",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 47,
                        "char": 26
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 51,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "services",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 52,
                        "char": 28
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 57,
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
                            "name": "mapper",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 58,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 58,
                            "char": 51
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
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 60,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "mapper",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 60,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 60,
                                        "char": 26
                                    }
                                ],
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 60,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 61,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Key value pairs with name as the key and a callable as the value for\n     * the service object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 59,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 58,
                    "last-line": 66,
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 67,
                            "char": 37
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 69,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 71,
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
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 71,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "mapper",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 71,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 71,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 71,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 71,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 71,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 71,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 71,
                                "char": 47
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
                                                            "value": "The service ",
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 73,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 73,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 73,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " has not been found in the locator",
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 74,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 74,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 74,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 74,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 75,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 77,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "list",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 77,
                                                    "char": 24
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "services",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 77,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 77,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 77,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 77,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 77,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 77,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 77,
                                "char": 41
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
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 78,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mapper",
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 78,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 78,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 78,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 78,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 78,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 79,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 79,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 79,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "string",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 79,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 79,
                                        "char": 45
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "services",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 80,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "create_instance",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "definition",
                                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                    "line": 80,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                "line": 80,
                                                                "char": 70
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 80,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 80,
                                                    "char": 71
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 81,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "instanceof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "definition",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 81,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "Closure",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 81,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 81,
                                                "char": 52
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property-array-index",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "services",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                    "line": 82,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "call_user_func",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "definition",
                                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                            "line": 82,
                                                                            "char": 69
                                                                        },
                                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                        "line": 82,
                                                                        "char": 69
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                "line": 82,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 82,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 83,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 83,
                                            "char": 18
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "services",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 84,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "definition",
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 84,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 84,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 85,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 86,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 88,
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
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 88,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 88,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 88,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 88,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 88,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 89,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get a service. If it is not in the mapper array, create a new object,\n     * set it and then return it.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 68,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 68,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 67,
                    "last-line": 93,
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 94,
                            "char": 37
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
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 96,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "mapper",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 96,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 96,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 96,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 96,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 96,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 97,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a service exists in the map array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 95,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 95,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 94,
                    "last-line": 101,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "sanitize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 102,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "sanitizers",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 102,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "noRecursive",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 102,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 102,
                            "char": 81
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "sanitizer",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 104,
                                    "char": 22
                                },
                                {
                                    "variable": "sanitizerKey",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 104,
                                    "char": 36
                                },
                                {
                                    "variable": "sanitizerName",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 104,
                                    "char": 51
                                },
                                {
                                    "variable": "sanitizerParams",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 104,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 138,
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
                                        "value": "sanitizers",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 138,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 138,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 138,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 138,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 142,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 142,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 142,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 143,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 144,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 149,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "sanitizers",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 149,
                                        "char": 55
                                    },
                                    "key": "sanitizerKey",
                                    "value": "sanitizer",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "sanitizer",
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 154,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 154,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 154,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 154,
                                                "char": 48
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "sanitizerName",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "sanitizerKey",
                                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                "line": 155,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 155,
                                                            "char": 56
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "sanitizerParams",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "sanitizer",
                                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                "line": 156,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 156,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 157,
                                                    "char": 18
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "sanitizerName",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "sanitizer",
                                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                "line": 158,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 158,
                                                            "char": 53
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "sanitizerParams",
                                                            "expr": {
                                                                "type": "empty-array",
                                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                "line": 159,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 159,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 160,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 167,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "identical",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 167,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 167,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 167,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 167,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "noRecursive",
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 167,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 167,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 167,
                                                "char": 59
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "value",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                    "line": 168,
                                                                    "char": 38
                                                                },
                                                                "name": "processArrayValues",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "value",
                                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                            "line": 169,
                                                                            "char": 30
                                                                        },
                                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                        "line": 169,
                                                                        "char": 30
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "sanitizerName",
                                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                            "line": 170,
                                                                            "char": 38
                                                                        },
                                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                        "line": 170,
                                                                        "char": 38
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "sanitizerParams",
                                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                            "line": 172,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                        "line": 172,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                "line": 172,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 172,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 173,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "value",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                    "line": 174,
                                                                    "char": 38
                                                                },
                                                                "name": "sanitizer",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "value",
                                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                            "line": 175,
                                                                            "char": 30
                                                                        },
                                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                        "line": 175,
                                                                        "char": 30
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "sanitizerName",
                                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                            "line": 176,
                                                                            "char": 38
                                                                        },
                                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                        "line": 176,
                                                                        "char": 38
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "sanitizerParams",
                                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                            "line": 178,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                        "line": 178,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                "line": 178,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 178,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 179,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 180,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 182,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 182,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 183,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 189,
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
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 189,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 189,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 189,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 189,
                                    "char": 35
                                },
                                "right": {
                                    "type": "not",
                                    "left": {
                                        "type": "variable",
                                        "value": "noRecursive",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 189,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 189,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 189,
                                "char": 50
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 190,
                                            "char": 25
                                        },
                                        "name": "processArrayValues",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 190,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 190,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "sanitizers",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 190,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 190,
                                                "char": 62
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 190,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 191,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 196,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 196,
                                    "char": 21
                                },
                                "name": "sanitizer",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 196,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 196,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "sanitizers",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 196,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 196,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 196,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 197,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sanitizes a value with a specified single or set of sanitizers\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 103,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 103,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 102,
                    "last-line": 201,
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 202,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "service",
                            "const": 0,
                            "data-type": "callable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 202,
                            "char": 55
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
                                    "property": "mapper",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 204,
                                            "char": 30
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "service",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 204,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 204,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 206,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 206,
                                        "char": 20
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 206,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 206,
                                    "char": 29
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 206,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 206,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 207,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set a new service to the mapper array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 203,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 202,
                    "last-line": 211,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "init",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "mapper",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 212,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 214,
                                    "char": 17
                                },
                                {
                                    "variable": "service",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 214,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 216,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "mapper",
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 216,
                                "char": 37
                            },
                            "key": "name",
                            "value": "service",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 217,
                                            "char": 18
                                        },
                                        "name": "set",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 217,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 217,
                                                "char": 27
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "service",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 217,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 217,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 217,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 218,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 219,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Loads the objects in the internal mapper array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 213,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 212,
                    "last-line": 223,
                    "char": 22
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "processArrayValues",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 225,
                            "char": 21
                        },
                        {
                            "type": "parameter",
                            "name": "sanitizerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 226,
                            "char": 29
                        },
                        {
                            "type": "parameter",
                            "name": "sanitizerParams",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 228,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 228,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "itemKey",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 230,
                                    "char": 20
                                },
                                {
                                    "variable": "itemValue",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 230,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 231,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "arrayValue",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 231,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 233,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "arrayValue",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 233,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 233,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 235,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "values",
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 235,
                                "char": 42
                            },
                            "key": "itemKey",
                            "value": "itemValue",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "arrayValue",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "itemKey",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 236,
                                                    "char": 35
                                                }
                                            ],
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 236,
                                                    "char": 44
                                                },
                                                "name": "sanitizer",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "itemValue",
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 237,
                                                            "char": 26
                                                        },
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 237,
                                                        "char": 26
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "sanitizerName",
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 238,
                                                            "char": 30
                                                        },
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 238,
                                                        "char": 30
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "sanitizerParams",
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 240,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                        "line": 240,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 240,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 240,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 241,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 243,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "arrayValue",
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 243,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 244,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Processes the array values with the relevant sanitizers\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 229,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 229,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 224,
                    "last-line": 248,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "sanitizer",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 250,
                            "char": 18
                        },
                        {
                            "type": "parameter",
                            "name": "sanitizerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 251,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "sanitizerParams",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 253,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 253,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "sanitizerObject",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 255,
                                    "char": 28
                                },
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 255,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 257,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 257,
                                        "char": 18
                                    },
                                    "name": "has",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "sanitizerName",
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 257,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 257,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 257,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 257,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 258,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 259,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 261,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "sanitizerObject",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 261,
                                            "char": 36
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "sanitizerName",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 261,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 261,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 261,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 261,
                                    "char": 55
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "params",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                                "line": 262,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                            "line": 262,
                                                            "char": 49
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 262,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 262,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "sanitizerParams",
                                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                    "line": 262,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                                "line": 262,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 262,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                    "line": 262,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 264,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "call_user_func_array",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "sanitizerObject",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 264,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 264,
                                        "char": 52
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                            "line": 264,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                        "line": 264,
                                        "char": 60
                                    }
                                ],
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 264,
                                "char": 61
                            },
                            "file": "\/app\/phalcon\/Filter\/Filter.zep",
                            "line": 265,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Internal sanitize wrapper for recursion\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Filter\/Filter.zep",
                                "line": 254,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 254,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 249,
                    "last-line": 266,
                    "char": 20
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "FILTER_ABSINT",
                    "default": {
                        "type": "string",
                        "value": "absint",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 22,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 23,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_ALNUM",
                    "default": {
                        "type": "string",
                        "value": "alnum",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 23,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 24,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_ALPHA",
                    "default": {
                        "type": "string",
                        "value": "alpha",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 24,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 25,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_BOOL",
                    "default": {
                        "type": "string",
                        "value": "bool",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 25,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 26,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_EMAIL",
                    "default": {
                        "type": "string",
                        "value": "email",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 26,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 27,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_FLOAT",
                    "default": {
                        "type": "string",
                        "value": "float",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 27,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 28,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_INT",
                    "default": {
                        "type": "string",
                        "value": "int",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 28,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 29,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_LOWER",
                    "default": {
                        "type": "string",
                        "value": "lower",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 29,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 30,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_LOWERFIRST",
                    "default": {
                        "type": "string",
                        "value": "lowerFirst",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 30,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 31,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_REGEX",
                    "default": {
                        "type": "string",
                        "value": "regex",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 31,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 32,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_REMOVE",
                    "default": {
                        "type": "string",
                        "value": "remove",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 32,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 33,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_REPLACE",
                    "default": {
                        "type": "string",
                        "value": "replace",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 33,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 34,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_SPECIAL",
                    "default": {
                        "type": "string",
                        "value": "special",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 34,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 35,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_SPECIALFULL",
                    "default": {
                        "type": "string",
                        "value": "specialFull",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 35,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 36,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_STRING",
                    "default": {
                        "type": "string",
                        "value": "string",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 36,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 37,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_STRIPTAGS",
                    "default": {
                        "type": "string",
                        "value": "striptags",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 37,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 38,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_TRIM",
                    "default": {
                        "type": "string",
                        "value": "trim",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 38,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 39,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_UPPER",
                    "default": {
                        "type": "string",
                        "value": "upper",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 39,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 40,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_UPPERFIRST",
                    "default": {
                        "type": "string",
                        "value": "upperFirst",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 40,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 41,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_UPPERWORDS",
                    "default": {
                        "type": "string",
                        "value": "upperWords",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 41,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 42,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FILTER_URL",
                    "default": {
                        "type": "string",
                        "value": "url",
                        "file": "\/app\/phalcon\/Filter\/Filter.zep",
                        "line": 42,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Filter\/Filter.zep",
                    "line": 46,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Filter\/Filter.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Filter\/Filter.zep",
        "line": 20,
        "char": 5
    }
]