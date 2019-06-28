[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Session\/Bag.zep",
        "line": 10,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Session",
        "file": "\/app\/phalcon\/Session\/Bag.zep",
        "line": 12,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection\\Collection",
                "file": "\/app\/phalcon\/Session\/Bag.zep",
                "line": 12,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Session\/Bag.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di",
                "file": "\/app\/phalcon\/Session\/Bag.zep",
                "line": 13,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Session\/Bag.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Session\/Bag.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Session\/Bag.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Session\/Bag.zep",
                "line": 15,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Session\/Bag.zep",
        "line": 30,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Session\\Bag\n *\n * This component helps to separate session data into \"namespaces\". Working by\n * this way you can easily create groups of session variables into the\n * application\n *\n * ```php\n * $user = new \\Phalcon\\Session\\Bag(\"user\");\n *\n * $user->name = \"Kimbra Johnson\";\n * $user->age  = 22;\n * ```\n *",
        "file": "\/app\/phalcon\/Session\/Bag.zep",
        "line": 31,
        "char": 5
    },
    {
        "type": "class",
        "name": "Bag",
        "abstract": 0,
        "final": 0,
        "extends": "Collection",
        "implements": [
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Session\/Bag.zep",
                "line": 32,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "container",
                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                    "line": 35,
                    "char": 11
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "name",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                        "line": 35,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                    "line": 37,
                    "char": 11
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "session",
                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                    "line": 41,
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 42,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 44,
                                    "char": 22
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 44,
                                    "char": 28
                                },
                                {
                                    "variable": "session",
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 44,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 46,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "name",
                                    "expr": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 46,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 46,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 48,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "container",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Di",
                                        "dynamic": 0,
                                        "name": "getDefault",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 48,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 48,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 50,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 50,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 50,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 50,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 50,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 50,
                                "char": 48
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
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "Exception",
                                                    "dynamic": 0,
                                                    "name": "containerServiceNotFound",
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "the 'session' service",
                                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                                "line": 54,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                            "line": 54,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                    "line": 55,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 55,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 55,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 56,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 58,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "session",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 58,
                                            "char": 41
                                        },
                                        "name": "getShared",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "session",
                                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                    "line": 58,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 58,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 58,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 58,
                                    "char": 60
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "container",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 59,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 59,
                                    "char": 40
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "session",
                                    "expr": {
                                        "type": "variable",
                                        "value": "session",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 60,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 60,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 62,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "session",
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 62,
                                            "char": 28
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                        "line": 62,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "name",
                                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                        "line": 62,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                    "line": 62,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 62,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 62,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 62,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 64,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 64,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 64,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 64,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 64,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "data",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 65,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 65,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 66,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 68,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "__construct",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 68,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 68,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 68,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 69,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Session\\Bag constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                        "line": 43,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                    "line": 42,
                    "last-line": 73,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "clear",
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "clear",
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 76,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 78,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 78,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "session",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 78,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 78,
                                    "char": 23
                                },
                                "name": "remove",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 78,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 78,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 78,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 78,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 78,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 79,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Destroys the session bag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                        "line": 75,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                    "line": 74,
                    "last-line": 83,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDI",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 86,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 86,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 86,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 87,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the DependencyInjector container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 85,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 85,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                        "line": 85,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                    "line": 84,
                    "last-line": 91,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "init",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 92,
                                "char": 42
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 92,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "init",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 94,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 94,
                                        "char": 26
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 94,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 95,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes a property from the internal bag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                        "line": 93,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                    "line": 92,
                    "last-line": 99,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "remove",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 100,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "remove",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 102,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 102,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 102,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 104,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 104,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "session",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 104,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 104,
                                    "char": 23
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 104,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 104,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 104,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 104,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 104,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 104,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 104,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 104,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 104,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 105,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes a property from the internal bag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                        "line": 101,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                    "line": 100,
                    "last-line": 109,
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
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 110,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 110,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "set",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 112,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 112,
                                        "char": 28
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 112,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 112,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 112,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 114,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 114,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "session",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 114,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 114,
                                    "char": 23
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 114,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 114,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 114,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 114,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 114,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                                "line": 114,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                                            "line": 114,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 114,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 114,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 115,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a value in the session bag\n     *",
                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                    "line": 110,
                    "last-line": 119,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDI",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Session\/Bag.zep",
                                "line": 120,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 120,
                            "char": 50
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
                                    "property": "container",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                                        "line": 122,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                                    "line": 122,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Bag.zep",
                            "line": 123,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the DependencyInjector container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Bag.zep",
                        "line": 121,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Bag.zep",
                    "line": 120,
                    "last-line": 124,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Session\/Bag.zep",
            "line": 31,
            "char": 5
        },
        "file": "\/app\/phalcon\/Session\/Bag.zep",
        "line": 31,
        "char": 5
    }
]