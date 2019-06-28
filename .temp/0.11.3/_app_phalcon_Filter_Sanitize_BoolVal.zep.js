[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Filter\\Sanitize",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Filter\\Sanitize\\BoolVal\n *\n * Sanitizes a value to boolean\n *",
        "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "BoolVal",
        "abstract": 0,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__invoke",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "input",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                            "line": 23,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "falseArray",
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                    "line": 25,
                                    "char": 23
                                },
                                {
                                    "variable": "trueArray",
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                    "line": 25,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                            "line": 27,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "trueArray",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                    "line": 27,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 27,
                                                "char": 31
                                            },
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "on",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                    "line": 27,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 27,
                                                "char": 35
                                            },
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "yes",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                    "line": 27,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 27,
                                                "char": 40
                                            },
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "y",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                    "line": 27,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 27,
                                                "char": 43
                                            },
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                    "line": 27,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 27,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                        "line": 27,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                    "line": 27,
                                    "char": 47
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "falseArray",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                    "line": 28,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 28,
                                                "char": 32
                                            },
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "off",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                    "line": 28,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 28,
                                                "char": 37
                                            },
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "no",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                    "line": 28,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 28,
                                                "char": 41
                                            },
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "n",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                    "line": 28,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 28,
                                                "char": 44
                                            },
                                            {
                                                "value": {
                                                    "type": "string",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                    "line": 28,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 28,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                        "line": 28,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                    "line": 28,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                            "line": 30,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                    "line": 30,
                                    "char": 19
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "in_array",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "input",
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 30,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                            "line": 30,
                                            "char": 35
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "trueArray",
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 30,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                            "line": 30,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                    "line": 30,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                "line": 30,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                        "line": 31,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                    "line": 32,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                            "line": 34,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                    "line": 34,
                                    "char": 19
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "in_array",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "input",
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 34,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                            "line": 34,
                                            "char": 35
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "falseArray",
                                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                                "line": 34,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                            "line": 34,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                    "line": 34,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                "line": 34,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                        "line": 35,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                    "line": 36,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                            "line": 38,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "cast",
                                "left": "bool",
                                "right": {
                                    "type": "variable",
                                    "value": "input",
                                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                    "line": 38,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                                "line": 38,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                            "line": 39,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * @var mixed input The text to sanitize\n     *",
                    "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
                    "line": 23,
                    "last-line": 40,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Filter\/Sanitize\/BoolVal.zep",
        "line": 18,
        "char": 5
    }
]