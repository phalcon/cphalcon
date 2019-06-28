[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Html",
        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Escaper",
                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                "line": 13,
                "char": 20
            }
        ],
        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\EscaperInterface",
                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                "line": 14,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\AbstractFactory",
                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                "line": 15,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * ServiceLocator implementation for Tag helpers\n *",
        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "TagFactory",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractFactory",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "escaper",
                    "docblock": "**\n     * @var <EscaperInterface>\n     *",
                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                    "line": 29,
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
                            "name": "escaper",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "EscaperInterface",
                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                "line": 30,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                            "line": 30,
                            "char": 59
                        },
                        {
                            "type": "parameter",
                            "name": "services",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                "line": 30,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                            "line": 30,
                            "char": 81
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
                                    "property": "escaper",
                                    "expr": {
                                        "type": "variable",
                                        "value": "escaper",
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 32,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                    "line": 32,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                            "line": 34,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                    "line": 34,
                                    "char": 14
                                },
                                "name": "init",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "services",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 34,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 34,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                "line": 34,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                            "line": 35,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * TagFactory constructor.\n     *",
                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                    "line": 30,
                    "last-line": 42,
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
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                            "line": 43,
                            "char": 44
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "definition",
                                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                    "line": 45,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                            "line": 47,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                    "line": 47,
                                    "char": 14
                                },
                                "name": "checkService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 47,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 47,
                                        "char": 32
                                    }
                                ],
                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                "line": 47,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                            "line": 49,
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
                                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                "line": 49,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "services",
                                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                "line": 49,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 49,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 49,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 49,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                    "line": 49,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                "line": 49,
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
                                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                        "line": 50,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "mapper",
                                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                        "line": 50,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                    "line": 50,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                    "line": 50,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                "line": 50,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 50,
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
                                                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                    "line": 51,
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
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                                "line": 51,
                                                                "char": 62
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "escaper",
                                                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                                "line": 51,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                            "line": 51,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                        "line": 51,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                                "line": 51,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 51,
                                            "char": 71
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                    "line": 52,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                            "line": 54,
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
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 54,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "services",
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 54,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                    "line": 54,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                    "line": 54,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                "line": 54,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                            "line": 55,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @param string name\n     *\n     * @return mixed\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                "line": 44,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                        "line": 44,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                    "line": 43,
                    "last-line": 57,
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
                                            "value": "a",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 60,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Html\\\\Helper\\\\Anchor",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 60,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 60,
                                        "char": 57
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "aRaw",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 61,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Html\\\\Helper\\\\AnchorRaw",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 61,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 61,
                                        "char": 60
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "body",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 62,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Html\\\\Helper\\\\Body",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 62,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 62,
                                        "char": 55
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "button",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 63,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Html\\\\Helper\\\\Button",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 63,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 63,
                                        "char": 57
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "close",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 64,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Html\\\\Helper\\\\Close",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 64,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 64,
                                        "char": 56
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 65,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Html\\\\Helper\\\\Element",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 65,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 65,
                                        "char": 58
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "elementRaw",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 66,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Html\\\\Helper\\\\ElementRaw",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 66,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 66,
                                        "char": 61
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "form",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 67,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Html\\\\Helper\\\\Form",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 67,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 67,
                                        "char": 55
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "img",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 68,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Html\\\\Helper\\\\Img",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 68,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 68,
                                        "char": 54
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "label",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 69,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Html\\\\Helper\\\\Label",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 69,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 69,
                                        "char": 56
                                    },
                                    {
                                        "key": {
                                            "type": "string",
                                            "value": "textarea",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 70,
                                            "char": 24
                                        },
                                        "value": {
                                            "type": "string",
                                            "value": "\\\\Phalcon\\\\Html\\\\Helper\\\\TextArea",
                                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                            "line": 71,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                        "line": 71,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                "line": 71,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                            "line": 72,
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
                                "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                                "line": 58,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                        "line": 58,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Html\/TagFactory.zep",
                    "line": 57,
                    "last-line": 73,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Html\/TagFactory.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Html\/TagFactory.zep",
        "line": 20,
        "char": 5
    }
]