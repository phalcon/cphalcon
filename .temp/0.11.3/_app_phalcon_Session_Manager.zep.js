[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Session\/Manager.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Session",
        "file": "\/app\/phalcon\/Session\/Manager.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "InvalidArgumentException",
                "file": "\/app\/phalcon\/Session\/Manager.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Session\/Manager.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "RuntimeException",
                "file": "\/app\/phalcon\/Session\/Manager.zep",
                "line": 14,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Session\/Manager.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "SessionHandlerInterface",
                "file": "\/app\/phalcon\/Session\/Manager.zep",
                "line": 15,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Session\/Manager.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Session\/Manager.zep",
                "line": 16,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Session\/Manager.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DI\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Session\/Manager.zep",
                "line": 17,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Session\/Manager.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Session\/Manager.zep",
                "line": 18,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Session\/Manager.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Session\\ManagerInterface",
                "file": "\/app\/phalcon\/Session\/Manager.zep",
                "line": 19,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Session\/Manager.zep",
        "line": 25,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Session\\Manager\n *\n * Session manager class\n *",
        "file": "\/app\/phalcon\/Session\/Manager.zep",
        "line": 26,
        "char": 5
    },
    {
        "type": "class",
        "name": "Manager",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ManagerInterface",
                "file": "\/app\/phalcon\/Session\/Manager.zep",
                "line": 26,
                "char": 42
            },
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Session\/Manager.zep",
                "line": 27,
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
                    "docblock": "**\n     * @var <DiInterface>\n     *",
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 35,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "handler",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 36,
                        "char": 27
                    },
                    "docblock": "**\n     * @var <SessionHandlerInterface>|null\n     *",
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 40,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "name",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 41,
                        "char": 20
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 45,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "options",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 46,
                        "char": 25
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 50,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "uniqueId",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 51,
                        "char": 24
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 55,
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
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 56,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 56,
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
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 58,
                                    "char": 14
                                },
                                "name": "setOptions",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 58,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 58,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 58,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 59,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Manager constructor.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 57,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 56,
                    "last-line": 63,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 64,
                            "char": 37
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 66,
                                    "char": 21
                                },
                                "name": "get",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 66,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 66,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 66,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 67,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Alias: Gets a session variable from an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 65,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 65,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 64,
                    "last-line": 71,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__isset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 72,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 74,
                                    "char": 21
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 74,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 74,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 74,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 75,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Alias: Check whether a session variable is set in an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 73,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 73,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 72,
                    "last-line": 79,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__set",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 80,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 80,
                            "char": 44
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
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 82,
                                    "char": 14
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 82,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 82,
                                        "char": 22
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 82,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 82,
                                        "char": 29
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 82,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 83,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Alias: Sets a session variable in an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 81,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 80,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__unset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 88,
                            "char": 39
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
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 90,
                                    "char": 14
                                },
                                "name": "remove",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 90,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 90,
                                        "char": 25
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 90,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 91,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Alias: Removes a session variable from an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 89,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 88,
                    "last-line": 95,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "destroy",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 98,
                                    "char": 19
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 98,
                                        "char": 26
                                    },
                                    "name": "exists",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 98,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 98,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "session_destroy",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 99,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 101,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "_SESSION",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 101,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 101,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 102,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 103,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Destroy\/end a session\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 97,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 96,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "exists",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "list",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "fcall",
                                        "name": "session_status",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 110,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 110,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "SESSION_ACTIVE",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 110,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 110,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 110,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 110,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 111,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether the session has been started\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 109,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 109,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 108,
                    "last-line": 115,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 116,
                            "char": 35
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 116,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 116,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "remove",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 116,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 116,
                            "char": 81
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "uniqueKey",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 118,
                                    "char": 22
                                },
                                {
                                    "variable": "value",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 118,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 118,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 120,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 120,
                                    "char": 20
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 120,
                                        "char": 27
                                    },
                                    "name": "exists",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 120,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 120,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 122,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 123,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 125,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "uniqueKey",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 125,
                                            "char": 30
                                        },
                                        "name": "getUniqueKey",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 125,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 125,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 125,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 125,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
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
                                                    "value": "_SESSION",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 126,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 126,
                                                "char": 42
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "uniqueKey",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 126,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 126,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "defaultValue",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 126,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 126,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 126,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 126,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 128,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "remove",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 128,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "list",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "_SESSION",
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 129,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "uniqueKey",
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 129,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 129,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 129,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 130,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 132,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 132,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 133,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets a session variable from an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 117,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 117,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 116,
                    "last-line": 137,
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
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 140,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 140,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 140,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 141,
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
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 139,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 139,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 139,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 138,
                    "last-line": 145,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHandler",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 148,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "handler",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 148,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 148,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 149,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the stored session handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "SessionHandlerInterface",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 147,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 147,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 147,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 146,
                    "last-line": 153,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getId",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "session_id",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 156,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 157,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the session id\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 155,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 155,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 154,
                    "last-line": 161,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getName",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "string",
                                    "value": "",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 164,
                                    "char": 15
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 164,
                                        "char": 22
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 164,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 164,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 164,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "name",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "session_name",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 165,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 165,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 166,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 168,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 168,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 168,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 168,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 169,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the name of the session\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 163,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 163,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 162,
                    "last-line": 173,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 174,
                            "char": 35
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "uniqueKey",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 176,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 178,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 178,
                                    "char": 20
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 178,
                                        "char": 27
                                    },
                                    "name": "exists",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 178,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 178,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 180,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 181,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 183,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "uniqueKey",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 183,
                                            "char": 30
                                        },
                                        "name": "getUniqueKey",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 183,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 183,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 183,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 183,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 185,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "_SESSION",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 185,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "uniqueKey",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 185,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 185,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 185,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 185,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 186,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether a session variable is set in an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 175,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 175,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 174,
                    "last-line": 190,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOptions",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 193,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "options",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 193,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 193,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 194,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get internal options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 192,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 192,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 191,
                    "last-line": 198,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "regenerateId",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "deleteOldSession",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 199,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 199,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "delete",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 201,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 203,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "delete",
                                    "expr": {
                                        "type": "cast",
                                        "left": "bool",
                                        "right": {
                                            "type": "variable",
                                            "value": "deleteOldSession",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 203,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 203,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 203,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 205,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 205,
                                    "char": 19
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 205,
                                        "char": 26
                                    },
                                    "name": "exists",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 205,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 205,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "session_regenerate_id",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "delete",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 206,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 206,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 206,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 207,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 209,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 209,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 210,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Regenerates the session id using the handler.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 200,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 200,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 200,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 199,
                    "last-line": 214,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerHandler",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "SessionHandlerInterface",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 215,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 215,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "session_set_save_handler",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 217,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 217,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 217,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 218,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Registers a handler with the session\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 216,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 216,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 215,
                    "last-line": 222,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 223,
                            "char": 38
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 225,
                                    "char": 20
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 225,
                                        "char": 27
                                    },
                                    "name": "exists",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 225,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 225,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 228,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 230,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "uniqueKey",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 230,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 232,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "uniqueKey",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 232,
                                            "char": 30
                                        },
                                        "name": "getUniqueKey",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 232,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 232,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 232,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 232,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 234,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "list",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "_SESSION",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 234,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "uniqueKey",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 234,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 234,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 234,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 235,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes a session variable from an application context\n     *",
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 223,
                    "last-line": 239,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 240,
                            "char": 35
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 240,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "uniqueKey",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 242,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 244,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 244,
                                    "char": 20
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 244,
                                        "char": 27
                                    },
                                    "name": "exists",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 244,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 244,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 247,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 249,
                            "char": 12
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "uniqueKey",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 249,
                                            "char": 40
                                        },
                                        "name": "getUniqueKey",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 249,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 249,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 249,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 249,
                                    "char": 58
                                },
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "_SESSION",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "uniqueKey",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 250,
                                            "char": 31
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 250,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 250,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 251,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a session variable in an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 241,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 240,
                    "last-line": 255,
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
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 256,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 256,
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
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 258,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 258,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 259,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the DependencyInjector container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 257,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 256,
                    "last-line": 263,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHandler",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "SessionHandlerInterface",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 264,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 264,
                            "char": 65
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
                                    "property": "handler",
                                    "expr": {
                                        "type": "variable",
                                        "value": "handler",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 266,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 266,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 268,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 268,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 269,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the handler for the session\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 265,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 265,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 265,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 264,
                    "last-line": 273,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setId",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "id",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 274,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "identical",
                                        "left": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 276,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 276,
                                                "char": 36
                                            },
                                            "name": "exists",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 276,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 276,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 276,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 276,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "RuntimeException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "The session has already been started. ",
                                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                        "line": 278,
                                                        "char": 56
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "To change the id, use regenerateId()",
                                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                        "line": 280,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 280,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 280,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 280,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 281,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 283,
                            "char": 18
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "session_id",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "id",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 283,
                                            "char": 22
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 283,
                                        "char": 22
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 283,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 285,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 285,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 286,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set session Id\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 275,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 275,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 275,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 274,
                    "last-line": 297,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 298,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 300,
                                        "char": 26
                                    },
                                    "name": "exists",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 300,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 300,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "InvalidArgumentException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Cannot set session name after a session has started",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 303,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 303,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 303,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 304,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 306,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "preg_match",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/^[\\p{L}\\p{N}_-]+$\/u",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 306,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 306,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 306,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 306,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 306,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 306,
                                    "char": 61
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 306,
                                "char": 61
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "InvalidArgumentException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "The name contains non alphanum characters",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 309,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 309,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 309,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 310,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 312,
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
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 312,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 312,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 314,
                            "char": 20
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "session_name",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 314,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 314,
                                        "char": 26
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 314,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 316,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 316,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 317,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the session name. Throw exception if the session has started\n     * and do not allow poop names\n     *\n     * @param  string name\n     *\n     * @throws InvalidArgumentException\n     *\n     * @return Manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 299,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 299,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 299,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 298,
                    "last-line": 321,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 322,
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
                                    "property": "uniqueId",
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
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 324,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 324,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "uniqueId",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 324,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 324,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 324,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 324,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 324,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 324,
                                    "char": 59
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 325,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 325,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 326,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets session's options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 323,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 322,
                    "last-line": 331,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "start",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 337,
                                    "char": 19
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 337,
                                        "char": 26
                                    },
                                    "name": "exists",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 337,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 337,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 338,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 339,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 344,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 344,
                                    "char": 19
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "headers_sent",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 344,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 344,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 345,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 346,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 348,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "list",
                                        "left": {
                                            "type": "instanceof",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 348,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "handler",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 348,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 348,
                                                "char": 46
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "SessionHandlerInterface",
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 348,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 348,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 348,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 348,
                                    "char": 73
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 348,
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
                                                    "type": "string",
                                                    "value": "The session handler is not valid",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 349,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 349,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 349,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 350,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 355,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 355,
                                    "char": 14
                                },
                                "name": "registerHandler",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 355,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "handler",
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 355,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 355,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 355,
                                        "char": 44
                                    }
                                ],
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 355,
                                "char": 45
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 360,
                            "char": 21
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "session_start",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 360,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 362,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 362,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 363,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Starts the session (if headers are already sent the session will not be\n     * started)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 333,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 333,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 332,
                    "last-line": 367,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "status",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "status",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 370,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 372,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "status",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "session_status",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 372,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 372,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 374,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "status",
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 374,
                                "char": 23
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "constant",
                                        "value": "PHP_SESSION_DISABLED",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 375,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 376,
                                                    "char": 46
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "SESSION_DISABLED",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 376,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 376,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 378,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 378,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "constant",
                                        "value": "PHP_SESSION_ACTIVE",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 378,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 379,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "SESSION_ACTIVE",
                                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                    "line": 379,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                                "line": 379,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 380,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 380,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 382,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "static-constant-access",
                                "left": {
                                    "type": "variable",
                                    "value": "self",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 382,
                                    "char": 34
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "SESSION_NONE",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 382,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 382,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 383,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the status of the current session.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 369,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 369,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 368,
                    "last-line": 387,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "getUniqueKey",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 388,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 390,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "uniqueId",
                                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                                            "line": 390,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 390,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "#",
                                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                                        "line": 390,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 390,
                                    "char": 35
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "key",
                                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                                    "line": 390,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 390,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Session\/Manager.zep",
                            "line": 391,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the key prefixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/Manager.zep",
                                "line": 389,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/Manager.zep",
                        "line": 389,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Session\/Manager.zep",
                    "line": 388,
                    "last-line": 392,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Session\/Manager.zep",
            "line": 26,
            "char": 5
        },
        "file": "\/app\/phalcon\/Session\/Manager.zep",
        "line": 26,
        "char": 5
    }
]