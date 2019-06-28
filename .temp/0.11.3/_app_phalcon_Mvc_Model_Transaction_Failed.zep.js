[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\Transaction",
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\MessageInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                "line": 13,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                "line": 14,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Transaction\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                "line": 15,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
        "line": 21,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Transaction\\Failed\n *\n * This class will be thrown to exit a try\/catch block for isolated transactions\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
        "line": 22,
        "char": 5
    },
    {
        "type": "class",
        "name": "Failed",
        "abstract": 0,
        "final": 0,
        "extends": "Exception",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "record",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                        "line": 24,
                        "char": 28
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                    "line": 28,
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                            "line": 29,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "record",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                "line": 29,
                                "char": 72
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                "line": 29,
                                "char": 80
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                            "line": 29,
                            "char": 80
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
                                    "property": "record",
                                    "expr": {
                                        "type": "variable",
                                        "value": "record",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                        "line": 31,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                    "line": 31,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                            "line": 33,
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
                                            "value": "message",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                            "line": 33,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                        "line": 33,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                "line": 33,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                            "line": 34,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\Transaction\\Failed constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                        "line": 30,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                    "line": 29,
                    "last-line": 38,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRecord",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                    "line": 41,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "record",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                    "line": 41,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                "line": 41,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                            "line": 42,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns validation record messages which stop the transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                    "line": 40,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                "line": 40,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                        "line": 40,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                    "line": 39,
                    "last-line": 46,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRecordMessages",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "record",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                    "line": 49,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                            "line": 51,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "record",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                            "line": 51,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "record",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                            "line": 51,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                        "line": 51,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                    "line": 51,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                            "line": 53,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "record",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                    "line": 53,
                                    "char": 21
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                    "line": 53,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                "line": 53,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "record",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                            "line": 54,
                                            "char": 27
                                        },
                                        "name": "getMessages",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                        "line": 54,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                    "line": 55,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                            "line": 57,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                    "line": 57,
                                    "char": 21
                                },
                                "name": "getMessage",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                "line": 57,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                            "line": 58,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns validation record messages which stop the transaction\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                    "line": 48,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                                "line": 48,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                        "line": 48,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
                    "line": 47,
                    "last-line": 59,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
            "line": 22,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Transaction\/Failed.zep",
        "line": 22,
        "char": 5
    }
]