[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Forms",
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Countable",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 13,
                "char": 14
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Iterator",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 14,
                "char": 13
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Injectable",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 15,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 16,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\FilterInterface",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 17,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Filter\\FilterInterface",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 18,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Forms\\Exception",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 19,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Forms\\ElementInterface",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 20,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Html\\Attributes",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 21,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Html\\Attributes\\AttributesInterface",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 22,
                "char": 48
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 23,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Messages",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 23,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 24,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Tag",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 24,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 25,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 25,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 26,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\ValidationInterface",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 26,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 30,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This component allows to build forms using an object-oriented interface\n *",
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 31,
        "char": 5
    },
    {
        "type": "class",
        "name": "Form",
        "abstract": 0,
        "final": 0,
        "extends": "Injectable",
        "implements": [
            {
                "type": "variable",
                "value": "Countable",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 31,
                "char": 51
            },
            {
                "type": "variable",
                "value": "Iterator",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 31,
                "char": 61
            },
            {
                "type": "variable",
                "value": "AttributesInterface",
                "file": "\/app\/phalcon\/Forms\/Form.zep",
                "line": 32,
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
                    "name": "attributes",
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 35,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "data",
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 37,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "elements",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 37,
                        "char": 28
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 39,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "elementsIndexed",
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 41,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "entity",
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 43,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "messages",
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 45,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "position",
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 47,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "options",
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 49,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "validation",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 49,
                            "char": 31
                        },
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 49,
                            "char": 37
                        }
                    ],
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 53,
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
                            "name": "entity",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 54,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 54,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "userOptions",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 54,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 54,
                            "char": 74
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
                                        "type": "and",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "entity",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 56,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 56,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 56,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "entity",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 56,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 56,
                                                "char": 56
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 56,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 56,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 56,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 56,
                                    "char": 66
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 56,
                                "char": 66
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
                                                    "value": "The base entity is not valid",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 57,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 57,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 57,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 58,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 60,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "entity",
                                    "expr": {
                                        "type": "variable",
                                        "value": "entity",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 60,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 60,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 65,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "userOptions",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 65,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 65,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 70,
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
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 70,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 70,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "initialize",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 70,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 70,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 70,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 71,
                                            "char": 18
                                        },
                                        "name": "initialize",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "entity",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 71,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 71,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "userOptions",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 71,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 71,
                                                "char": 51
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 71,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 72,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 77,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 77,
                                    "char": 14
                                },
                                "name": "setAttributes",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "new",
                                            "class": "Attributes",
                                            "dynamic": 0,
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 77,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 77,
                                        "char": 45
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 77,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 78,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Forms\\Form constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 55,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 54,
                    "last-line": 82,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "add",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ElementInterface",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 83,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 83,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "position",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 83,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 83,
                            "char": 75
                        },
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 83,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 83,
                            "char": 93
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 85,
                                    "char": 17
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 85,
                                    "char": 22
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 85,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 86,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "elements",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 86,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 91,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 91,
                                            "char": 28
                                        },
                                        "name": "getName",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 91,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 91,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 96,
                            "char": 15
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 96,
                                    "char": 17
                                },
                                "name": "setForm",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 96,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 96,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 96,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 98,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "position",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 98,
                                        "char": 22
                                    },
                                    "right": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 98,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 98,
                                    "char": 30
                                },
                                "right": {
                                    "type": "empty",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 98,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "elements",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 98,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 98,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 98,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 98,
                                "char": 53
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "elements",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 102,
                                                    "char": 36
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "element",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 102,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 102,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 103,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "elements",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 104,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 104,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 109,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 109,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "elements",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 109,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 109,
                                        "char": 46
                                    },
                                    "key": "key",
                                    "value": "value",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 110,
                                                    "char": 25
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "position",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 110,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 110,
                                                "char": 36
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "type",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 111,
                                                        "char": 29
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "elements",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "name",
                                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                            "line": 115,
                                                                            "char": 42
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "element",
                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                        "line": 115,
                                                                        "char": 53
                                                                    },
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 115,
                                                                    "char": 53
                                                                },
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "elements",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "key",
                                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                            "line": 116,
                                                                            "char": 41
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                        "line": 116,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 116,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 117,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "else_statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "elements",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "key",
                                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                            "line": 121,
                                                                            "char": 41
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "value",
                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                        "line": 121,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 121,
                                                                    "char": 50
                                                                },
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "elements",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "name",
                                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                            "line": 122,
                                                                            "char": 42
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "element",
                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                        "line": 122,
                                                                        "char": 53
                                                                    },
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 122,
                                                                    "char": 53
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 123,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 124,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "elements",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "key",
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 128,
                                                                    "char": 37
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 128,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 128,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 129,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 130,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 132,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "elements",
                                            "expr": {
                                                "type": "variable",
                                                "value": "elements",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 132,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 132,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 133,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 135,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 135,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 136,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds an element to the form\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Form",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 84,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 84,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 84,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 83,
                    "last-line": 143,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "bind",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 144,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "entity",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 144,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "whitelist",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 144,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 144,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "filter",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 146,
                                    "char": 19
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 146,
                                    "char": 24
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 146,
                                    "char": 31
                                },
                                {
                                    "variable": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 146,
                                    "char": 40
                                },
                                {
                                    "variable": "filters",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 146,
                                    "char": 49
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 146,
                                    "char": 60
                                },
                                {
                                    "variable": "filteredValue",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 146,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 147,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "method",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 147,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 149,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 149,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "elements",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 149,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 149,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 149,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 149,
                                "char": 42
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
                                                    "value": "There are no elements in the form",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 150,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 150,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 150,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 151,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 153,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "filter",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 153,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 153,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 155,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 155,
                                "char": 32
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "element",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 159,
                                                "char": 52
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 159,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "elements",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 159,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 159,
                                                    "char": 46
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 159,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 159,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 159,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 159,
                                        "char": 52
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 161,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 166,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "whitelist",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 166,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 166,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 166,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 166,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "in_array",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "key",
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 167,
                                                                "char": 33
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 167,
                                                            "char": 33
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "whitelist",
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 167,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 167,
                                                            "char": 44
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 167,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 167,
                                                "char": 46
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 169,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 170,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 175,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "filters",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "element",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 175,
                                                    "char": 35
                                                },
                                                "name": "getFilters",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 175,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 175,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 177,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "filters",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 177,
                                        "char": 24
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "filter",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 178,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 178,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 178,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 178,
                                                "char": 44
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "container",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 179,
                                                                    "char": 42
                                                                },
                                                                "name": "getDI",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 179,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 179,
                                                            "char": 50
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "filter",
                                                            "expr": {
                                                                "type": "type-hint",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "FilterInterface",
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 180,
                                                                    "char": 80
                                                                },
                                                                "right": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "container",
                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                        "line": 180,
                                                                        "char": 62
                                                                    },
                                                                    "name": "getShared",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "filter",
                                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                                "line": 180,
                                                                                "char": 79
                                                                            },
                                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                            "line": 180,
                                                                            "char": 79
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 180,
                                                                    "char": 80
                                                                },
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 180,
                                                                "char": 80
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 180,
                                                            "char": 80
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 181,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 186,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "filteredValue",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "filter",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 186,
                                                            "char": 44
                                                        },
                                                        "name": "sanitize",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 186,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 186,
                                                                "char": 59
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "filters",
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 186,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 186,
                                                                "char": 68
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 186,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 186,
                                                    "char": 69
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 187,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "filteredValue",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 188,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 188,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 189,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 194,
                                    "char": 15
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
                                                    "value": "set",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 194,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "camelize",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "key",
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 194,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 194,
                                                            "char": 44
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 194,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 194,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 194,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 195,
                                    "char": 14
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
                                                    "value": "entity",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 195,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 195,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "method",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 195,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 195,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 195,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "entity",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 196,
                                                    "char": 24
                                                },
                                                "name": "method",
                                                "call-type": 2,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "filteredValue",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 196,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 196,
                                                        "char": 47
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 196,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 198,
                                            "char": 24
                                        },
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 199,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 204,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-dynamic-object-property",
                                            "operator": "assign",
                                            "variable": "entity",
                                            "property": "key",
                                            "expr": {
                                                "type": "variable",
                                                "value": "filteredValue",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 204,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 204,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 205,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 207,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "data",
                                    "expr": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 207,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 207,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 209,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 209,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 210,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Binds data to the entity\n     *\n     * @param object entity\n     * @param array whitelist\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Form",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 145,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 145,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 145,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 144,
                    "last-line": 216,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "clear",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "fields",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 217,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 217,
                            "char": 44
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "elements",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 219,
                                    "char": 21
                                },
                                {
                                    "variable": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 219,
                                    "char": 30
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 219,
                                    "char": 36
                                },
                                {
                                    "variable": "field",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 219,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 221,
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
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 221,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 221,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 221,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 221,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 223,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "fields",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 223,
                                    "char": 21
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 223,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 223,
                                "char": 28
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
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 224,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 224,
                                            "char": 26
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 225,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "fields",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 226,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 226,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 226,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 226,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "fields",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 227,
                                                "char": 37
                                            },
                                            "value": "field",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "isset",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "data",
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 228,
                                                                "char": 34
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 228,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 228,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 228,
                                                        "char": 42
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "unset",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "data",
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 229,
                                                                    "char": 35
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "field",
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 229,
                                                                    "char": 41
                                                                },
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 229,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 230,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 231,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 232,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 233,
                                                        "char": 30
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "field",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 233,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 233,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 233,
                                                "char": 38
                                            },
                                            "statements": [
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "data",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 234,
                                                            "char": 31
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 234,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 234,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 235,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 236,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 237,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 239,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "data",
                                    "expr": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 239,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 239,
                                    "char": 30
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "elements",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 240,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "elements",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 240,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 240,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 240,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 247,
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
                                        "value": "elements",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 247,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 247,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 247,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 247,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "fields",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 248,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 248,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 248,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "elements",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 249,
                                                "char": 41
                                            },
                                            "value": "element",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "scall",
                                                    "expr": {
                                                        "type": "scall",
                                                        "dynamic-class": 0,
                                                        "class": "Tag",
                                                        "dynamic": 0,
                                                        "name": "setDefault",
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "element",
                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                        "line": 251,
                                                                        "char": 33
                                                                    },
                                                                    "name": "getName",
                                                                    "call-type": 1,
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 251,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 251,
                                                                "char": 43
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "element",
                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                        "line": 252,
                                                                        "char": 33
                                                                    },
                                                                    "name": "getDefault",
                                                                    "call-type": 1,
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 253,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 253,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 253,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 254,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 255,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "fields",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 256,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 256,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 256,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 256,
                                                "char": 43
                                            },
                                            "statements": [
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "elements",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 257,
                                                        "char": 45
                                                    },
                                                    "value": "element",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "in_array",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "element",
                                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                                "line": 258,
                                                                                "char": 45
                                                                            },
                                                                            "name": "getName",
                                                                            "call-type": 1,
                                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                            "line": 258,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                        "line": 258,
                                                                        "char": 55
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "fields",
                                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                            "line": 258,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                        "line": 258,
                                                                        "char": 63
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 258,
                                                                "char": 65
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "scall",
                                                                    "expr": {
                                                                        "type": "scall",
                                                                        "dynamic-class": 0,
                                                                        "class": "Tag",
                                                                        "dynamic": 0,
                                                                        "name": "setDefault",
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "mcall",
                                                                                    "variable": {
                                                                                        "type": "variable",
                                                                                        "value": "element",
                                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                                        "line": 260,
                                                                                        "char": 41
                                                                                    },
                                                                                    "name": "getName",
                                                                                    "call-type": 1,
                                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                                    "line": 260,
                                                                                    "char": 51
                                                                                },
                                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                                "line": 260,
                                                                                "char": 51
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "mcall",
                                                                                    "variable": {
                                                                                        "type": "variable",
                                                                                        "value": "element",
                                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                                        "line": 261,
                                                                                        "char": 41
                                                                                    },
                                                                                    "name": "getDefault",
                                                                                    "call-type": 1,
                                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                                    "line": 262,
                                                                                    "char": 29
                                                                                },
                                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                                "line": 262,
                                                                                "char": 29
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                        "line": 262,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 263,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 264,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 265,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fetch",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "element",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 266,
                                                            "char": 56
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "elements",
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 266,
                                                                "char": 47
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "fields",
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 266,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 266,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 266,
                                                        "char": 56
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "scall",
                                                            "expr": {
                                                                "type": "scall",
                                                                "dynamic-class": 0,
                                                                "class": "Tag",
                                                                "dynamic": 0,
                                                                "name": "setDefault",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "element",
                                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                                "line": 268,
                                                                                "char": 37
                                                                            },
                                                                            "name": "getName",
                                                                            "call-type": 1,
                                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                            "line": 268,
                                                                            "char": 47
                                                                        },
                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                        "line": 268,
                                                                        "char": 47
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "element",
                                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                                "line": 269,
                                                                                "char": 37
                                                                            },
                                                                            "name": "getDefault",
                                                                            "call-type": 1,
                                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                            "line": 270,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                        "line": 270,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 270,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 271,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 272,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 273,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 274,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 276,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 276,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 277,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Clears every element in the form to its default value\n     *\n     * @param array|string|null fields\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Form",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 218,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 218,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 218,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 217,
                    "last-line": 281,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "count",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "count",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 284,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "elements",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 284,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 284,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 284,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 284,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 285,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the number of elements in the form\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 283,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 283,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 282,
                    "last-line": 289,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "current",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 292,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 294,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "element",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 294,
                                        "char": 66
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 294,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "elementsIndexed",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 294,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 294,
                                            "char": 49
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 294,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "position",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 294,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 294,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 294,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 294,
                                    "char": 66
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 294,
                                "char": 66
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 295,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 296,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 298,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "element",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 298,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 299,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current element in the iterator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 290,
                                    "char": 53
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 290,
                                "char": 53
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 291,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 291,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 290,
                    "last-line": 303,
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
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 304,
                            "char": 37
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 306,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 308,
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
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 308,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 308,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "elements",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 308,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 308,
                                                "char": 51
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 308,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 308,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 308,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 308,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 308,
                                "char": 58
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
                                                            "value": "Element with ID=",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 310,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 310,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 310,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " is not part of the form",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 311,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 311,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 311,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 311,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 312,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 314,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "element",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 314,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 315,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an element added to the form by its name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 305,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 305,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 305,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 304,
                    "last-line": 319,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAction",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "cast",
                                "left": "string",
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 322,
                                            "char": 30
                                        },
                                        "name": "getAttributes",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 322,
                                        "char": 47
                                    },
                                    "name": "get",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "action",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 322,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 322,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 322,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 322,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 323,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the form's action\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 321,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 321,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 320,
                    "last-line": 327,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getElements",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 330,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "elements",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 330,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 330,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 331,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the form elements added to the form\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ElementInterface",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 329,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 329,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 329,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 328,
                    "last-line": 337,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEntity",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 340,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "entity",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 340,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 340,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 341,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the entity related to the model\n     *\n     * @return object\n     *",
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 338,
                    "last-line": 345,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLabel",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 346,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 348,
                                    "char": 20
                                },
                                {
                                    "variable": "label",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 348,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 350,
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
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 350,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 350,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "elements",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 350,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 350,
                                                "char": 51
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 350,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 350,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 350,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 350,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 350,
                                "char": 58
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
                                                            "value": "Element with ID=",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 352,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 352,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 352,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " is not part of the form",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 353,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 353,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 353,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 353,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 354,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 356,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "label",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 356,
                                            "char": 29
                                        },
                                        "name": "getLabel",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 356,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 356,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 361,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "label",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 361,
                                    "char": 19
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 361,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 362,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 363,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 365,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "label",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 365,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 366,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a label for an element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 347,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 347,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 346,
                    "last-line": 380,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessages",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "messages",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 383,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 385,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "messages",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 385,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 385,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 385,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 385,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 387,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "and",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "messages",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 387,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 387,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 387,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 387,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "instanceof",
                                            "left": {
                                                "type": "variable",
                                                "value": "messages",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 387,
                                                "char": 61
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "Messages",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 387,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 387,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 387,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 387,
                                    "char": 73
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 387,
                                "char": 73
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "new",
                                        "class": "Messages",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 388,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 389,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 391,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "messages",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 391,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 392,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the messages generated in the validation.\n     *\n     * ```php\n     * if ($form->isValid($_POST) == false) {\n     *     $messages = $form->getMessages();\n     *\n     *     foreach ($messages as $message) {\n     *         echo $message, \"<br>\";\n     *     }\n     * }\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Messages",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 381,
                                    "char": 49
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 381,
                                "char": 49
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 382,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 382,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 381,
                    "last-line": 396,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessagesFor",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 397,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 399,
                                        "char": 18
                                    },
                                    "name": "has",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 399,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 399,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 399,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 399,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "new",
                                        "class": "Messages",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 400,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 401,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 403,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 403,
                                        "char": 21
                                    },
                                    "name": "get",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 403,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 403,
                                            "char": 30
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 403,
                                    "char": 32
                                },
                                "name": "getMessages",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 403,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 404,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the messages generated for a specific element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Messages",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 398,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 398,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 398,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 397,
                    "last-line": 408,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getUserOption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "option",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 409,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 409,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 409,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 411,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 413,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 413,
                                        "char": 48
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 413,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 413,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 413,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "option",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 413,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 413,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 413,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 413,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultValue",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 414,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 415,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 417,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 417,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 418,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the value of an option if present\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 410,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 410,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 409,
                    "last-line": 422,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getUserOptions",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 425,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "options",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 425,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 425,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 426,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the options for the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 424,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 424,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 423,
                    "last-line": 430,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 431,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "entity",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 433,
                                    "char": 19
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 433,
                                    "char": 26
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 433,
                                    "char": 32
                                },
                                {
                                    "variable": "internalEntity",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 433,
                                    "char": 48
                                },
                                {
                                    "variable": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 433,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 434,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "forbidden",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 434,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 435,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "method",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 435,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 437,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "entity",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 437,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "entity",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 437,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 437,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 437,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 438,
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
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 438,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 438,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 438,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 438,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 443,
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
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 443,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 443,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "getCustomValue",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 443,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 443,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 443,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 444,
                                            "char": 25
                                        },
                                        "name": "getCustomValue",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 444,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 444,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "entity",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 444,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 444,
                                                "char": 55
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 444,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 444,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 444,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 445,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 447,
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
                                        "value": "entity",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 447,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 447,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 447,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 447,
                                "char": 36
                            },
                            "statements": [
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
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 451,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "camelize",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "name",
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 451,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 451,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 451,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 451,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 451,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 452,
                                    "char": 14
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
                                                    "value": "entity",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 452,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 452,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "method",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 452,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 452,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 452,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "entity",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 453,
                                                    "char": 31
                                                },
                                                "name": "method",
                                                "call-type": 2,
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 453,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 454,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 459,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 459,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "property-dynamic-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "entity",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 459,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 459,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 459,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 459,
                                        "char": 45
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 460,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 461,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 462,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 464,
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
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 464,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 464,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 464,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 464,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 468,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 468,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 468,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 468,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 468,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 469,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 470,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 471,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 473,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "forbidden",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "validation",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 474,
                                                    "char": 23
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 474,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 474,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "action",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 475,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 475,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 475,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "useroption",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 476,
                                                    "char": 23
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 476,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 476,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "useroptions",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 477,
                                                    "char": 24
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 477,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 477,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "entity",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 478,
                                                    "char": 19
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 478,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 478,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "elements",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 479,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 479,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 479,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "messages",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 480,
                                                    "char": 21
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 480,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 480,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "messagesfor",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 481,
                                                    "char": 24
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 481,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 481,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "label",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 482,
                                                    "char": 18
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 482,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 482,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 483,
                                                    "char": 18
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 483,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 483,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "di",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 484,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 484,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 484,
                                                "char": 32
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "eventsmanager",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 485,
                                                    "char": 26
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 486,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 486,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 486,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 486,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 491,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "internalEntity",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtolower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 491,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 491,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 491,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 491,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 492,
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
                                        "value": "forbidden",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 492,
                                        "char": 27
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "internalEntity",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 492,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 492,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 492,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 493,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 494,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 499,
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
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 499,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "camelize",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "name",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 499,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 499,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 499,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 499,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 499,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 500,
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
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 500,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 500,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "method",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 500,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 500,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 500,
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
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 501,
                                            "char": 25
                                        },
                                        "name": "method",
                                        "call-type": 2,
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 501,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 502,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 507,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Tag",
                                "dynamic": 0,
                                "name": "hasValue",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 507,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 507,
                                        "char": 30
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 507,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Tag",
                                        "dynamic": 0,
                                        "name": "getValue",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 508,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 508,
                                                "char": 38
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 508,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 509,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 514,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 514,
                                    "char": 48
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 514,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "elements",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 514,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 514,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 514,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 514,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 514,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 515,
                                            "char": 28
                                        },
                                        "name": "getDefault",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 515,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 516,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 518,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 518,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 519,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets a value from the internal related entity or from the default value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 431,
                                "char": 51
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 432,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 432,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 431,
                    "last-line": 523,
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
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 524,
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
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 529,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "elements",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 529,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 529,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 529,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 529,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 529,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 530,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if the form contains an element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 525,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 525,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 524,
                    "last-line": 534,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasMessagesFor",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 535,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 537,
                                            "char": 21
                                        },
                                        "name": "getMessagesFor",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 537,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 537,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 537,
                                        "char": 43
                                    },
                                    "name": "count",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 537,
                                    "char": 52
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 537,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 537,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 538,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if messages were generated for a specific element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 536,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 536,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 535,
                    "last-line": 545,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isValid",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 546,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 546,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "entity",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 546,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 546,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "messages",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 548,
                                    "char": 21
                                },
                                {
                                    "variable": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 548,
                                    "char": 30
                                },
                                {
                                    "variable": "validators",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 548,
                                    "char": 42
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 548,
                                    "char": 48
                                },
                                {
                                    "variable": "filters",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 548,
                                    "char": 57
                                },
                                {
                                    "variable": "validator",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 548,
                                    "char": 68
                                },
                                {
                                    "variable": "validation",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 548,
                                    "char": 80
                                },
                                {
                                    "variable": "elementMessage",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 549,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 550,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "validationStatus",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 550,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 552,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "empty",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 552,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "elements",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 552,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 552,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 552,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 553,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 554,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 559,
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
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 559,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 559,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 559,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 559,
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
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 560,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 560,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 560,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 560,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 561,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 566,
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
                                        "value": "entity",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 566,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 566,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 566,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 566,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 567,
                                            "char": 18
                                        },
                                        "name": "bind",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 567,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 567,
                                                "char": 28
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "entity",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 567,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 567,
                                                "char": 36
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 567,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 568,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 569,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "entity",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 569,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 569,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 569,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 569,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 569,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 570,
                                                    "char": 22
                                                },
                                                "name": "bind",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "data",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 570,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 570,
                                                        "char": 32
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 570,
                                                                "char": 39
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "entity",
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 570,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 570,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 570,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 570,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 571,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 572,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 577,
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
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 577,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 577,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "beforeValidation",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 577,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 577,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 577,
                                "char": 50
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 578,
                                                "char": 21
                                            },
                                            "name": "beforeValidation",
                                            "call-type": 3,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 578,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 578,
                                                    "char": 45
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "entity",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 578,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 578,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 578,
                                            "char": 57
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 578,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 578,
                                        "char": 65
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 579,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 580,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 581,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 583,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "validationStatus",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 583,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 583,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 585,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "validation",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 585,
                                            "char": 31
                                        },
                                        "name": "getValidation",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 585,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 585,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 587,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 587,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 587,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 587,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 587,
                                    "char": 41
                                },
                                "right": {
                                    "type": "not",
                                    "left": {
                                        "type": "list",
                                        "left": {
                                            "type": "instanceof",
                                            "left": {
                                                "type": "variable",
                                                "value": "validation",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 587,
                                                "char": 65
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "ValidationInterface",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 587,
                                                "char": 86
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 587,
                                            "char": 86
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 587,
                                        "char": 88
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 587,
                                    "char": 88
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 587,
                                "char": 88
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "validation",
                                            "expr": {
                                                "type": "new",
                                                "class": "Validation",
                                                "dynamic": 0,
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 589,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 589,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 590,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 592,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 592,
                                    "char": 29
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "elements",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 592,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 592,
                                "char": 39
                            },
                            "value": "element",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "validators",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "element",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 593,
                                                    "char": 38
                                                },
                                                "name": "getValidators",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 593,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 593,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 595,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "fcall",
                                            "name": "count",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "validators",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 595,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 595,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 595,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 595,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 595,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 597,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 602,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "name",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "element",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 602,
                                                    "char": 32
                                                },
                                                "name": "getName",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 602,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 602,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 607,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "validators",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 607,
                                        "char": 41
                                    },
                                    "value": "validator",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "validation",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 608,
                                                    "char": 28
                                                },
                                                "name": "add",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 608,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 608,
                                                        "char": 37
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "validator",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 608,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 608,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 608,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 609,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 614,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "filters",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "element",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 614,
                                                    "char": 35
                                                },
                                                "name": "getFilters",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 614,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 614,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 619,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "filters",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 619,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 619,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 619,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 619,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "validation",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 620,
                                                    "char": 28
                                                },
                                                "name": "setFilters",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 620,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 620,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "filters",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 620,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 620,
                                                        "char": 53
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 620,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 621,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 622,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 627,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "messages",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 627,
                                            "char": 35
                                        },
                                        "name": "validate",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 627,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 627,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "entity",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 627,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 627,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 627,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 627,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 628,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "messages",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 628,
                                    "char": 21
                                },
                                "name": "count",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 628,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "iterator",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "messages",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 630,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 630,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 630,
                                        "char": 54
                                    },
                                    "value": "elementMessage",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 631,
                                                        "char": 22
                                                    },
                                                    "name": "get",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "elementMessage",
                                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                    "line": 631,
                                                                    "char": 42
                                                                },
                                                                "name": "getField",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                                "line": 631,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 631,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 631,
                                                    "char": 55
                                                },
                                                "name": "appendMessage",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "elementMessage",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 631,
                                                            "char": 84
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 631,
                                                        "char": 84
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 631,
                                                "char": 85
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 632,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 634,
                                    "char": 20
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 634,
                                            "char": 22
                                        },
                                        "name": "rewind",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 634,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 636,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "validationStatus",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 636,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 636,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 637,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 642,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "validationStatus",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 642,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 642,
                                "char": 30
                            },
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
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 643,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 643,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 644,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 649,
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
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 649,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 649,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "afterValidation",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 649,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 649,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 649,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 650,
                                            "char": 18
                                        },
                                        "name": "afterValidation",
                                        "call-type": 3,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "messages",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 650,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 650,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 650,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 651,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 656,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "validationStatus",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 656,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 657,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Validates the form\n     *\n     * @param array data\n     * @param object entity\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 547,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 547,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 546,
                    "last-line": 661,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "key",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 664,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "position",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 664,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 664,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 665,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current position\/key in the iterator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 663,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 663,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 662,
                    "last-line": 669,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "label",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 670,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 670,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 670,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 672,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 674,
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
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 674,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 674,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "elements",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 674,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 674,
                                                "char": 51
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 674,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 674,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 674,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 674,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 674,
                                "char": 58
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
                                                            "value": "Element with ID=",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 676,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 676,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 676,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " is not part of the form",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 677,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 677,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 677,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 677,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 678,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 680,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 680,
                                    "char": 24
                                },
                                "name": "label",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 680,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 680,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 680,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 681,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generate the label of an element added to the form including HTML\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 671,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 671,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 670,
                    "last-line": 685,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "next",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-incr",
                                    "variable": "this",
                                    "property": "position",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 688,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 689,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Moves the internal iteration pointer to the next position\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 687,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 686,
                    "last-line": 693,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "render",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 694,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 694,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 694,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 696,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 698,
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
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 698,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 698,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "elements",
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 698,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 698,
                                                "char": 51
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 698,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 698,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 698,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 698,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 698,
                                "char": 58
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
                                                            "value": "Element with ID=",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 700,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                            "line": 700,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 700,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " is not part of the form",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 701,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 701,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 701,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 701,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 702,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 704,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "element",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 704,
                                    "char": 24
                                },
                                "name": "render",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 704,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 704,
                                        "char": 42
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 704,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 705,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders a specific item in the form\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 695,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 695,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 694,
                    "last-line": 709,
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 710,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 715,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "elements",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 715,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 715,
                                        "char": 32
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 715,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 715,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 715,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 716,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "elements",
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 716,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 716,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 716,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 716,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 718,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 718,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 719,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 724,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "elementsIndexed",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 724,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 724,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 726,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 726,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 727,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes an element from the form\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 711,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 711,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 710,
                    "last-line": 731,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rewind",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "position",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 734,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 734,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 736,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "elementsIndexed",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_values",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 736,
                                                        "char": 55
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "elements",
                                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                        "line": 736,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                    "line": 736,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                                "line": 736,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 736,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 736,
                                    "char": 65
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 737,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Rewinds the internal iterator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 733,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 732,
                    "last-line": 743,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAction",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "action",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 744,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 746,
                                        "char": 14
                                    },
                                    "name": "getAttributes",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 746,
                                    "char": 31
                                },
                                "name": "set",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "action",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 746,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 746,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "action",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 746,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 746,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 746,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 748,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 748,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 749,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the form's action\n     *\n     * @return Form\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Form",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 745,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 745,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 745,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 744,
                    "last-line": 755,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setEntity",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "entity",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 756,
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
                                    "property": "entity",
                                    "expr": {
                                        "type": "variable",
                                        "value": "entity",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 758,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 758,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 760,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 760,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 761,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the entity related to the model\n     *\n     * @param object entity\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Form",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 757,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 757,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 757,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 756,
                    "last-line": 765,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setUserOption",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "option",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 766,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 766,
                            "char": 59
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
                                    "property": "options",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "option",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 768,
                                            "char": 33
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 768,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 768,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 770,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 770,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 771,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets an option for the form\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Form",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 767,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 767,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 767,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 766,
                    "last-line": 775,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setUserOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 776,
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
                                    "property": "options",
                                    "expr": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 778,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 778,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 780,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 780,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 781,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets options for the element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Form",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 777,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 777,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 777,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 776,
                    "last-line": 785,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "valid",
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
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 788,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "elementsIndexed",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 788,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 788,
                                        "char": 43
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 788,
                                            "char": 49
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                                            "line": 788,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 788,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 788,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 788,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 789,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if the current element in the iterator is valid\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 787,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 787,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 786,
                    "last-line": 793,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAttributes",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 796,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "attributes",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 796,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 796,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 797,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Get Form attributes collection\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Attributes",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 795,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 795,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 795,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 794,
                    "last-line": 801,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Attributes",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 802,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 802,
                            "char": 58
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
                                    "property": "attributes",
                                    "expr": {
                                        "type": "variable",
                                        "value": "attributes",
                                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                                        "line": 804,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 804,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 806,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 806,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Forms\/Form.zep",
                            "line": 807,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Set form attributes collection\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AttributesInterface",
                                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                                    "line": 803,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Forms\/Form.zep",
                                "line": 803,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Forms\/Form.zep",
                        "line": 803,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Forms\/Form.zep",
                    "line": 802,
                    "last-line": 808,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Forms\/Form.zep",
            "line": 31,
            "char": 5
        },
        "file": "\/app\/phalcon\/Forms\/Form.zep",
        "line": 31,
        "char": 5
    }
]