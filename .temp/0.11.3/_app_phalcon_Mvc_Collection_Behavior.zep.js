[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Collection",
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\CollectionInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                "line": 13,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Collection\\Behavior\n *\n * This is an optional base class for ORM behaviors\n *",
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
        "line": 20,
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
                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                "line": 21,
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
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                    "line": 26,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                "line": 27,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 27,
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
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                        "line": 29,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                    "line": 29,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 30,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Collection\\Behavior\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                    "line": 27,
                    "last-line": 36,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                "line": 37,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 37,
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
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                    "line": 39,
                                    "char": 20
                                },
                                {
                                    "variable": "eventOptions",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                    "line": 39,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 41,
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
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                            "line": 41,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                            "line": 41,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                        "line": 41,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                    "line": 41,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 42,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "eventName",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                    "line": 42,
                                    "char": 24
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                    "line": 42,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                "line": 42,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "eventOptions",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                            "line": 43,
                                            "char": 55
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                                "line": 43,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "eventName",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                                "line": 43,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                            "line": 43,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                        "line": 43,
                                        "char": 55
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "eventOptions",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                                "line": 44,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                            "line": 45,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                    "line": 46,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                        "line": 46,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                    "line": 47,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 48,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "options",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                "line": 48,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 49,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the behavior options related to an event\n     *\n     * @return array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                    "line": 37,
                    "last-line": 53,
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
                                "value": "CollectionInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                "line": 54,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 54,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 54,
                            "char": 77
                        },
                        {
                            "type": "parameter",
                            "name": "arguments",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                "line": 54,
                                "char": 99
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 54,
                            "char": 99
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                "line": 56,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 57,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Acts as fallbacks when a missing method is called on the collection\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                    "line": 54,
                    "last-line": 61,
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
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 62,
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
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                            "line": 64,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                            "line": 64,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                        "line": 64,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "eventName",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                        "line": 64,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                    "line": 64,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                "line": 64,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 65,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                "line": 63,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                        "line": 63,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                    "line": 62,
                    "last-line": 69,
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
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 70,
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
                                "value": "CollectionInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                "line": 70,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 70,
                            "char": 68
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                                "line": 72,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                            "line": 73,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * This method receives the notifications from the EventsManager\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
                    "line": 70,
                    "last-line": 74,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
            "line": 20,
            "char": 14
        },
        "file": "\/app\/phalcon\/Mvc\/Collection\/Behavior.zep",
        "line": 20,
        "char": 14
    }
]