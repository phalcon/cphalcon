[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Helper\/Number.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Helper",
        "file": "\/app\/phalcon\/Helper\/Number.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Exception",
                "file": "\/app\/phalcon\/Helper\/Number.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Helper\/Number.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Helper\\number\n *\n * This class offers numeric functions for the framework\n *",
        "file": "\/app\/phalcon\/Helper\/Number.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Number",
        "abstract": 0,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "final",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "between",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Number.zep",
                            "line": 25,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "from",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Number.zep",
                            "line": 25,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "to",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Helper\/Number.zep",
                            "line": 25,
                            "char": 69
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "greater-equal",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Helper\/Number.zep",
                                        "line": 27,
                                        "char": 22
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "from",
                                        "file": "\/app\/phalcon\/Helper\/Number.zep",
                                        "line": 27,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Number.zep",
                                    "line": 27,
                                    "char": 30
                                },
                                "right": {
                                    "type": "less-equal",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Helper\/Number.zep",
                                        "line": 27,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "to",
                                        "file": "\/app\/phalcon\/Helper\/Number.zep",
                                        "line": 27,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Helper\/Number.zep",
                                    "line": 27,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Helper\/Number.zep",
                                "line": 27,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Helper\/Number.zep",
                            "line": 28,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Helper method to get an array element or a default\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Helper\/Number.zep",
                                "line": 26,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Helper\/Number.zep",
                        "line": 26,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Helper\/Number.zep",
                    "line": 25,
                    "last-line": 29,
                    "char": 32
                }
            ],
            "file": "\/app\/phalcon\/Helper\/Number.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Helper\/Number.zep",
        "line": 20,
        "char": 5
    }
]