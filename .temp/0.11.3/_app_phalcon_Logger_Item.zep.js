[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/Item.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger",
        "file": "\/app\/phalcon\/Logger\/Item.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Logger\\Item\n *\n * Represents each item in a logging transaction\n *\n *",
        "file": "\/app\/phalcon\/Logger\/Item.zep",
        "line": 19,
        "char": 5
    },
    {
        "type": "class",
        "name": "Item",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "context",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                            "line": 21,
                            "char": 29
                        }
                    ],
                    "file": "\/app\/phalcon\/Logger\/Item.zep",
                    "line": 27,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "message",
                    "docblock": "**\n     * Log message\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                            "line": 28,
                            "char": 29
                        }
                    ],
                    "file": "\/app\/phalcon\/Logger\/Item.zep",
                    "line": 34,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "name",
                    "docblock": "**\n     * Log message\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                            "line": 35,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Logger\/Item.zep",
                    "line": 41,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "time",
                    "docblock": "**\n     * Log timestamp\n     *\n     * @var integer\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                            "line": 42,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Logger\/Item.zep",
                    "line": 48,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "type",
                    "docblock": "**\n     * Log type\n     *\n     * @var integer\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                            "line": 49,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Logger\/Item.zep",
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
                            "name": "message",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                            "line": 54,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                            "line": 54,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                            "line": 54,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "time",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Logger\/Item.zep",
                                "line": 54,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                            "line": 54,
                            "char": 84
                        },
                        {
                            "type": "parameter",
                            "name": "context",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Item.zep",
                                "line": 54,
                                "char": 102
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                            "line": 54,
                            "char": 102
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
                                    "property": "message",
                                    "expr": {
                                        "type": "variable",
                                        "value": "message",
                                        "file": "\/app\/phalcon\/Logger\/Item.zep",
                                        "line": 56,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Item.zep",
                                    "line": 56,
                                    "char": 36
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "name",
                                    "expr": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Logger\/Item.zep",
                                        "line": 57,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Item.zep",
                                    "line": 57,
                                    "char": 33
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "type",
                                    "expr": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Logger\/Item.zep",
                                        "line": 58,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Item.zep",
                                    "line": 58,
                                    "char": 33
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "time",
                                    "expr": {
                                        "type": "variable",
                                        "value": "time",
                                        "file": "\/app\/phalcon\/Logger\/Item.zep",
                                        "line": 59,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Item.zep",
                                    "line": 59,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                            "line": 61,
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
                                        "value": "context",
                                        "file": "\/app\/phalcon\/Logger\/Item.zep",
                                        "line": 61,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Item.zep",
                                    "line": 61,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Logger\/Item.zep",
                                    "line": 61,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Logger\/Item.zep",
                                "line": 61,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "context",
                                            "expr": {
                                                "type": "variable",
                                                "value": "context",
                                                "file": "\/app\/phalcon\/Logger\/Item.zep",
                                                "line": 62,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                                            "line": 62,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Item.zep",
                                    "line": 63,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Item.zep",
                            "line": 64,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Logger\\Item constructor\n     *",
                    "file": "\/app\/phalcon\/Logger\/Item.zep",
                    "line": 54,
                    "last-line": 65,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Logger\/Item.zep",
            "line": 19,
            "char": 5
        },
        "file": "\/app\/phalcon\/Logger\/Item.zep",
        "line": 19,
        "char": 5
    }
]