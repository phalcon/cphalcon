[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by phalcon-api and AuraPHP\n * @link    https:\/\/github.com\/phalcon\/phalcon-api\n * @license https:\/\/github.com\/phalcon\/phalcon-api\/blob\/master\/LICENSE\n * @link    https:\/\/github.com\/auraphp\/Aura.Payload\n * @license https:\/\/github.com\/auraphp\/Aura.Payload\/blob\/3.x\/LICENSE\n *\n * @see Original inspiration for the https:\/\/github.com\/phalcon\/phalcon-api\n *",
        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
        "line": 19,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Domain\\Payload",
        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Domain\\Payload\\PayloadInterface",
                "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                "line": 21,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
        "line": 25,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Holds the payload\n *",
        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
        "line": 26,
        "char": 5
    },
    {
        "type": "class",
        "name": "Payload",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "PayloadInterface",
                "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                "line": 27,
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
                    "name": "extras",
                    "docblock": "**\n     * Extra information\n     *\n     * @var mixed\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 33,
                            "char": 28
                        }
                    ],
                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                    "line": 39,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "input",
                    "docblock": "**\n     * Input\n     *\n     * @var mixed\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 40,
                            "char": 27
                        }
                    ],
                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                    "line": 46,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "messages",
                    "docblock": "**\n     * Messages\n     *\n     * @var mixed\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 47,
                            "char": 30
                        }
                    ],
                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                    "line": 53,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "status",
                    "docblock": "**\n     * Status\n     *\n     * @var mixed\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 54,
                            "char": 28
                        }
                    ],
                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                    "line": 60,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "output",
                    "docblock": "**\n     * Output\n     *\n     * @var mixed\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 61,
                            "char": 28
                        }
                    ],
                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                    "line": 65,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setExtras",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "extras",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 66,
                            "char": 41
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
                                    "property": "extras",
                                    "expr": {
                                        "type": "variable",
                                        "value": "extras",
                                        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                        "line": 68,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                    "line": 68,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 70,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                "line": 70,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 71,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets arbitrary extra domain information.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "PayloadInterface",
                                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                    "line": 67,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                "line": 67,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                        "line": 67,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                    "line": 66,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setInput",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "input",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 76,
                            "char": 39
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
                                    "property": "input",
                                    "expr": {
                                        "type": "variable",
                                        "value": "input",
                                        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                        "line": 78,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                    "line": 78,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 80,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                "line": 80,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 81,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the domain input.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "PayloadInterface",
                                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                    "line": 77,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                "line": 77,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                        "line": 77,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                    "line": 76,
                    "last-line": 85,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setMessages",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "messages",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 86,
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
                                    "property": "messages",
                                    "expr": {
                                        "type": "variable",
                                        "value": "messages",
                                        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                        "line": 88,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                    "line": 88,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 90,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                "line": 90,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 91,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the domain messages.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "PayloadInterface",
                                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                    "line": 87,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                "line": 87,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                        "line": 87,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                    "line": 86,
                    "last-line": 95,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setOutput",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "output",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 96,
                            "char": 41
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
                                    "property": "output",
                                    "expr": {
                                        "type": "variable",
                                        "value": "output",
                                        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                        "line": 98,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                    "line": 98,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 100,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                "line": 100,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 101,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the domain output.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "PayloadInterface",
                                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                    "line": 97,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                "line": 97,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                        "line": 97,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                    "line": 96,
                    "last-line": 105,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setStatus",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "status",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 106,
                            "char": 41
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
                                    "property": "status",
                                    "expr": {
                                        "type": "variable",
                                        "value": "status",
                                        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                        "line": 108,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                    "line": 108,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 110,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                "line": 110,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                            "line": 111,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the payload status.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "PayloadInterface",
                                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                    "line": 107,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                                "line": 107,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                        "line": 107,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
                    "line": 106,
                    "last-line": 112,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
            "line": 26,
            "char": 5
        },
        "file": "\/app\/phalcon\/Domain\/Payload\/Payload.zep",
        "line": 26,
        "char": 5
    }
]