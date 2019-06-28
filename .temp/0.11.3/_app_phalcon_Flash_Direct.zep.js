[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Flash\/Direct.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Flash",
        "file": "\/app\/phalcon\/Flash\/Direct.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Flash\\AbstractFlash",
                "file": "\/app\/phalcon\/Flash\/Direct.zep",
                "line": 13,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Flash\/Direct.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This is a variant of the Phalcon\\Flash that immediately outputs any message\n * passed to it\n *",
        "file": "\/app\/phalcon\/Flash\/Direct.zep",
        "line": 19,
        "char": 5
    },
    {
        "type": "class",
        "name": "Direct",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractFlash",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "message",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/Direct.zep",
                            "line": 24,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/Direct.zep",
                            "line": 24,
                            "char": 53
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
                                    "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                    "line": 26,
                                    "char": 21
                                },
                                "name": "outputMessage",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                            "line": 26,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                        "line": 26,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                            "line": 26,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                        "line": 26,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                "line": 26,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Flash\/Direct.zep",
                            "line": 27,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Outputs a message\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                "line": 25,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Flash\/Direct.zep",
                        "line": 25,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/Direct.zep",
                    "line": 24,
                    "last-line": 31,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "output",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "remove",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                "line": 32,
                                "char": 46
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Flash\/Direct.zep",
                            "line": 32,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "message",
                                    "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                    "line": 34,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/Direct.zep",
                            "line": 36,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                    "line": 36,
                                    "char": 29
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "messages",
                                    "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                    "line": 36,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                "line": 36,
                                "char": 39
                            },
                            "value": "message",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "echo",
                                    "expressions": [
                                        {
                                            "type": "variable",
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                            "line": 37,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                    "line": 38,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/Direct.zep",
                            "line": 40,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "remove",
                                "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                "line": 40,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "scall",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "parent",
                                        "dynamic": 0,
                                        "name": "clear",
                                        "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                        "line": 41,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Flash\/Direct.zep",
                                    "line": 42,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Flash\/Direct.zep",
                            "line": 43,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prints the messages accumulated in the flasher\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Flash\/Direct.zep",
                        "line": 33,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Flash\/Direct.zep",
                    "line": 32,
                    "last-line": 44,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Flash\/Direct.zep",
            "line": 19,
            "char": 5
        },
        "file": "\/app\/phalcon\/Flash\/Direct.zep",
        "line": 19,
        "char": 5
    }
]