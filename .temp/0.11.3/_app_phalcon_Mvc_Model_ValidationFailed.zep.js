[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\ValidationFailed\n *\n * This exception is generated when a model fails to save a record\n * Phalcon\\Mvc\\Model must be set up to have this behavior\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
        "line": 21,
        "char": 5
    },
    {
        "type": "class",
        "name": "ValidationFailed",
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
                    "name": "messages",
                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                    "line": 25,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "model",
                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                    "line": 31,
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
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                "line": 32,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                            "line": 32,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "validationMessages",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                            "line": 32,
                            "char": 82
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "messageStr",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 34,
                                    "char": 23
                                },
                                {
                                    "variable": "message",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 34,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                            "line": 36,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "fcall",
                                    "name": "count",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "validationMessages",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                                "line": 36,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                            "line": 36,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 36,
                                    "char": 38
                                },
                                "right": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 36,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                "line": 36,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "message",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "validationMessages",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                                    "line": 40,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                                    "line": 40,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                                "line": 40,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                            "line": 40,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 45,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "messageStr",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "message",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                                    "line": 45,
                                                    "char": 38
                                                },
                                                "name": "getMessage",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                                "line": 45,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                            "line": 45,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 46,
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
                                            "variable": "messageStr",
                                            "expr": {
                                                "type": "string",
                                                "value": "Validation failed",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                                "line": 47,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                            "line": 47,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 48,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                            "line": 50,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "model",
                                    "expr": {
                                        "type": "variable",
                                        "value": "model",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                        "line": 50,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 50,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                            "line": 51,
                            "char": 11
                        },
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
                                        "value": "validationMessages",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                        "line": 51,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 51,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                            "line": 53,
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
                                            "value": "messageStr",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                            "line": 53,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                        "line": 53,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                "line": 53,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                            "line": 54,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\ValidationFailed constructor\n     *\n     * @param Message[] validationMessages\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                        "line": 33,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                    "line": 32,
                    "last-line": 58,
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
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 61,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "messages",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 61,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                "line": 61,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                            "line": 62,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the complete group of messages produced in the validation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Message",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 60,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                "line": 60,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                        "line": 60,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                    "line": 59,
                    "last-line": 66,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getModel",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 69,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "model",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 69,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                "line": 69,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                            "line": 70,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the model that generated the messages\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                    "line": 68,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                                "line": 68,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                        "line": 68,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
                    "line": 67,
                    "last-line": 71,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
            "line": 21,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/ValidationFailed.zep",
        "line": 21,
        "char": 5
    }
]