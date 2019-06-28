[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\BehaviorInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                "line": 14,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Behavior\n *\n * This is an optional base class for ORM behaviors\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
        "line": 21,
        "char": 8
    },
    {
        "type": "class",
        "name": "Behavior",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "BehaviorInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                "line": 22,
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
                    "name": "options",
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                    "line": 30,
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                "line": 31,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 31,
                            "char": 51
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
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                        "line": 33,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                    "line": 33,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 34,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Model\\Behavior\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                        "line": 32,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                    "line": 31,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                "line": 41,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 41,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                    "line": 43,
                                    "char": 20
                                },
                                {
                                    "variable": "eventOptions",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                    "line": 43,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 45,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "options",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                            "line": 45,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                            "line": 45,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                        "line": 45,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                    "line": 45,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 47,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "eventName",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                    "line": 47,
                                    "char": 24
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                    "line": 47,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                "line": 47,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "eventOptions",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                                "line": 48,
                                                "char": 56
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                                    "line": 48,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "eventName",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                                    "line": 48,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                                "line": 48,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                            "line": 48,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                        "line": 48,
                                        "char": 56
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                                "line": 49,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                            "line": 50,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                    "line": 52,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "eventOptions",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                        "line": 52,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                    "line": 53,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 55,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "options",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                "line": 55,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 56,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the behavior options related to an event\n     *\n     * @return array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                    "line": 41,
                    "last-line": 60,
                    "char": 22
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "missingMethod",
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
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                "line": 61,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 61,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 61,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "arguments",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                "line": 61,
                                "char": 94
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 61,
                            "char": 94
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                "line": 63,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 64,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Acts as fallbacks when a missing method is called on the model\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                    "line": 61,
                    "last-line": 68,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "mustTakeAction",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 69,
                            "char": 56
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                            "line": 71,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                            "line": 71,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                        "line": 71,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "eventName",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                        "line": 71,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                    "line": 71,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                "line": 71,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 72,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks whether the behavior must take action on certain event\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                "line": 70,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                        "line": 70,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                    "line": 69,
                    "last-line": 76,
                    "char": 22
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notify",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 77,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                "line": 77,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 77,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                                "line": 79,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                            "line": 80,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * This method receives the notifications from the EventsManager\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
                    "line": 77,
                    "last-line": 81,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
            "line": 21,
            "char": 14
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Behavior.zep",
        "line": 21,
        "char": 14
    }
]