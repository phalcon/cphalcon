[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Events\/Manager.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Events",
        "file": "\/app\/phalcon\/Events\/Manager.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Closure",
                "file": "\/app\/phalcon\/Events\/Manager.zep",
                "line": 13,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Events\/Manager.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\Event",
                "file": "\/app\/phalcon\/Events\/Manager.zep",
                "line": 14,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Events\/Manager.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "SplPriorityQueue",
                "file": "\/app\/phalcon\/Events\/Manager.zep",
                "line": 15,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Events\/Manager.zep",
        "line": 24,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Events\\Manager\n *\n * Phalcon Events Manager, offers an easy way to intercept and manipulate, if\n * needed, the normal flow of operation. With the EventsManager the developer\n * can create hooks or plugins that will offer monitoring of data, manipulation,\n * conditional execution and much more.\n *",
        "file": "\/app\/phalcon\/Events\/Manager.zep",
        "line": 25,
        "char": 5
    },
    {
        "type": "class",
        "name": "Manager",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ManagerInterface",
                "file": "\/app\/phalcon\/Events\/Manager.zep",
                "line": 26,
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
                    "name": "collect",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 32,
                        "char": 30
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 36,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "enablePriorities",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 37,
                        "char": 39
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 39,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "events",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 39,
                        "char": 28
                    },
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 41,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "responses",
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 47,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "attach",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventType",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 48,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 48,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "priority",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 1,
                            "default": {
                                "type": "static-constant-access",
                                "left": {
                                    "type": "variable",
                                    "value": "self",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 48,
                                    "char": 98
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "DEFAULT_PRIORITY",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 48,
                                    "char": 98
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 48,
                                "char": 98
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 48,
                            "char": 98
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "priorityQueue",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 50,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 52,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 52,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 52,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 52,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 52,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 52,
                                "char": 46
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
                                                    "value": "Event handler must be an Object",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 53,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 53,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 53,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 54,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 56,
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
                                        "value": "priorityQueue",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 56,
                                        "char": 58
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 56,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "events",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 56,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 56,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "eventType",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 56,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 56,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 56,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 56,
                                "char": 58
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "priorityQueue",
                                            "expr": {
                                                "type": "new",
                                                "class": "SplPriorityQueue",
                                                "dynamic": 0,
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 58,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 58,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 61,
                                    "char": 25
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "priorityQueue",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 61,
                                            "char": 27
                                        },
                                        "name": "setExtractFlags",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "SplPriorityQueue",
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 63,
                                                        "char": 13
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "EXTR_DATA",
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 63,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 63,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 63,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 63,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 66,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "events",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "eventType",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 66,
                                                    "char": 39
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "priorityQueue",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 66,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 66,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 67,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 69,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 69,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "enablePriorities",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 69,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 69,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 69,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "priority",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 70,
                                                    "char": 50
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "DEFAULT_PRIORITY",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 70,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 70,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 70,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 71,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 74,
                            "char": 21
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "priorityQueue",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 74,
                                    "char": 23
                                },
                                "name": "insert",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 74,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 74,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "priority",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 74,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 74,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 74,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 75,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Attach a listener to the events manager\n     *\n     * @param object|callable handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 49,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 48,
                    "last-line": 79,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "arePrioritiesEnabled",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 82,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "enablePriorities",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 82,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 82,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 83,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns if priorities are enabled\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 81,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 81,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 80,
                    "last-line": 88,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "collectResponses",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "collect",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 89,
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
                                    "property": "collect",
                                    "expr": {
                                        "type": "variable",
                                        "value": "collect",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 91,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 91,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 92,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Tells the event manager if it needs to collect all the responses returned\n     * by every registered listener in a single fire\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 90,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 89,
                    "last-line": 98,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "detach",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventType",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 99,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 99,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "priorityQueue",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 101,
                                    "char": 26
                                },
                                {
                                    "variable": "newPriorityQueue",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 101,
                                    "char": 44
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 101,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 103,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 103,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 103,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 103,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 103,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 103,
                                "char": 46
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
                                                    "value": "Event handler must be an Object",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 104,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 104,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 104,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 105,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 107,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "priorityQueue",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 107,
                                    "char": 57
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 107,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "events",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 107,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 107,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "eventType",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 107,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 107,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 107,
                                "char": 57
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "newPriorityQueue",
                                            "expr": {
                                                "type": "new",
                                                "class": "SplPriorityQueue",
                                                "dynamic": 0,
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 112,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 112,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 114,
                                    "char": 28
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "newPriorityQueue",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 114,
                                            "char": 30
                                        },
                                        "name": "setExtractFlags",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "SplPriorityQueue",
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 116,
                                                        "char": 13
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "EXTR_DATA",
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 116,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 116,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 116,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 116,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 118,
                                    "char": 25
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "priorityQueue",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 118,
                                            "char": 27
                                        },
                                        "name": "setExtractFlags",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "SplPriorityQueue",
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 120,
                                                        "char": 13
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "EXTR_BOTH",
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 120,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 120,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 120,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 120,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 122,
                                    "char": 25
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "priorityQueue",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 122,
                                            "char": 27
                                        },
                                        "name": "top",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 122,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 124,
                                    "char": 17
                                },
                                {
                                    "type": "while",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "priorityQueue",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 124,
                                            "char": 33
                                        },
                                        "name": "valid",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 124,
                                        "char": 42
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
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "priorityQueue",
                                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                            "line": 125,
                                                            "char": 42
                                                        },
                                                        "name": "current",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 125,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 125,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 127,
                                            "char": 29
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "priorityQueue",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 127,
                                                    "char": 31
                                                },
                                                "name": "next",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 127,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 129,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 129,
                                                        "char": 24
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "data",
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 129,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 129,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "handler",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 129,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 129,
                                                "char": 43
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "newPriorityQueue",
                                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                            "line": 130,
                                                            "char": 38
                                                        },
                                                        "name": "insert",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "data",
                                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                        "line": 131,
                                                                        "char": 29
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "data",
                                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                        "line": 131,
                                                                        "char": 34
                                                                    },
                                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                    "line": 131,
                                                                    "char": 35
                                                                },
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 131,
                                                                "char": 35
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "data",
                                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                        "line": 132,
                                                                        "char": 29
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "priority",
                                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                        "line": 132,
                                                                        "char": 38
                                                                    },
                                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                    "line": 133,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 133,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 133,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 134,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 135,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 137,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "events",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "eventType",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 137,
                                                    "char": 39
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "newPriorityQueue",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 137,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 137,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 138,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 139,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Detach the listener from the events manager\n     *\n     * @param object handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 100,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 99,
                    "last-line": 143,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "detachAll",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 144,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 144,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "type",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 146,
                                    "char": 19
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 146,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 146,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "events",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 147,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 147,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 148,
                                    "char": 9
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
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 149,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "events",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 149,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 149,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 149,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 149,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 149,
                                        "char": 41
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
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 150,
                                                        "char": 28
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "events",
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 150,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 150,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 150,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 150,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 151,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 152,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 153,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes all events from the EventsManager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 145,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 144,
                    "last-line": 157,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "enablePriorities",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "enablePriorities",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 158,
                            "char": 59
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
                                    "property": "enablePriorities",
                                    "expr": {
                                        "type": "variable",
                                        "value": "enablePriorities",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 160,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 160,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 161,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set if priorities are enabled in the EventsManager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 159,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 158,
                    "last-line": 174,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fire",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventType",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 175,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "source",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 175,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 175,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 175,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "cancelable",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 175,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 175,
                            "char": 88
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "events",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 177,
                                    "char": 19
                                },
                                {
                                    "variable": "eventParts",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 177,
                                    "char": 31
                                },
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 177,
                                    "char": 37
                                },
                                {
                                    "variable": "eventName",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 177,
                                    "char": 48
                                },
                                {
                                    "variable": "event",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 177,
                                    "char": 55
                                },
                                {
                                    "variable": "status",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 177,
                                    "char": 63
                                },
                                {
                                    "variable": "fireEvents",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 177,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 179,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "events",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 179,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "events",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 179,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 179,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 179,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 181,
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
                                        "value": "events",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 181,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 181,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 181,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 181,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 182,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 183,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 186,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "memstr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "eventType",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 186,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 186,
                                                "char": 38
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": ":",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 186,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 186,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 186,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 186,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 186,
                                "char": 43
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
                                                        "type": "string",
                                                        "value": "Invalid event type ",
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 187,
                                                        "char": 53
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "eventType",
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 187,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 187,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 187,
                                                "char": 64
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 187,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 188,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 190,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "eventParts",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "explode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": ":",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 190,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 190,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "eventType",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 190,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 190,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 190,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 190,
                                    "char": 47
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "type",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "eventParts",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 191,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 191,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 191,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 191,
                                    "char": 33
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "eventName",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "eventParts",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 192,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 192,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 192,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 192,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 194,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "status",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 194,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 194,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 197,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 197,
                                    "char": 17
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "collect",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 197,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 197,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "responses",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 198,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 198,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 199,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 202,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "event",
                                    "expr": {
                                        "type": "new",
                                        "class": "Event",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "eventName",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 202,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 202,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "source",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 202,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 202,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 202,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 202,
                                                "char": 54
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cancelable",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 202,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 202,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 202,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 202,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 205,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "fireEvents",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 205,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "events",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 205,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 205,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 205,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 205,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "fireEvents",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 206,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 206,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 206,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 206,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "status",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                            "line": 208,
                                                            "char": 35
                                                        },
                                                        "name": "fireQueue",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "fireEvents",
                                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                    "line": 208,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 208,
                                                                "char": 56
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "event",
                                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                    "line": 208,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 208,
                                                                "char": 63
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 208,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 208,
                                                    "char": 64
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 209,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 210,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 213,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "fireEvents",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 213,
                                    "char": 48
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "events",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 213,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "eventType",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 213,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 213,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 213,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "fireEvents",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 214,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 214,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 214,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 214,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "status",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                            "line": 216,
                                                            "char": 35
                                                        },
                                                        "name": "fireQueue",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "fireEvents",
                                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                    "line": 216,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 216,
                                                                "char": 56
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "event",
                                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                    "line": 216,
                                                                    "char": 63
                                                                },
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 216,
                                                                "char": 63
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 216,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 216,
                                                    "char": 64
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 217,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 218,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 220,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "status",
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 220,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 221,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Fires an event in the events manager causing the active listeners to be\n     * notified about it\n     *\n     *```php\n     * $eventsManager->fire(\"db\", $connection);\n     *```\n     *\n     * @param object source\n     * @param mixed  data\n     * @return mixed\n     *",
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 175,
                    "last-line": 227,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "fireQueue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "queue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "SplPriorityQueue",
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 228,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 228,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "event",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "EventInterface",
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 228,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 228,
                            "char": 85
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "status",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 230,
                                    "char": 19
                                },
                                {
                                    "variable": "eventName",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 230,
                                    "char": 30
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 230,
                                    "char": 36
                                },
                                {
                                    "variable": "iterator",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 230,
                                    "char": 46
                                },
                                {
                                    "variable": "source",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 230,
                                    "char": 54
                                },
                                {
                                    "variable": "handler",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 230,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 231,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "collect",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 231,
                                    "char": 21
                                },
                                {
                                    "variable": "cancelable",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 231,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 233,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "status",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 233,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 233,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 236,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "eventName",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "event",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 236,
                                            "char": 31
                                        },
                                        "name": "getType",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 236,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 236,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 238,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "eventName",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 238,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 238,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "string",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 238,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 238,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 238,
                                "char": 48
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
                                                    "value": "The event type not valid",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 239,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 239,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 239,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 240,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 243,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "source",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "event",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 243,
                                            "char": 28
                                        },
                                        "name": "getSource",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 243,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 243,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 246,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "event",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 246,
                                            "char": 26
                                        },
                                        "name": "getData",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 246,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 246,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 249,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cancelable",
                                    "expr": {
                                        "type": "cast",
                                        "left": "bool",
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "event",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 249,
                                                "char": 39
                                            },
                                            "name": "isCancelable",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 249,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 249,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 249,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 252,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collect",
                                    "expr": {
                                        "type": "cast",
                                        "left": "bool",
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 252,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "collect",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 252,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 252,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 252,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 252,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 255,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "iterator",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "variable",
                                            "value": "queue",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 255,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 255,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 255,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 258,
                            "char": 16
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "iterator",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 258,
                                    "char": 18
                                },
                                "name": "top",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 258,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 260,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "iterator",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 260,
                                    "char": 24
                                },
                                "name": "valid",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 260,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handler",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "iterator",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 262,
                                                    "char": 36
                                                },
                                                "name": "current",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 262,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 262,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 264,
                                    "char": 20
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "iterator",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 264,
                                            "char": 22
                                        },
                                        "name": "next",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 264,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 267,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "handler",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 267,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 267,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 267,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 267,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 267,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 269,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 272,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "instanceof",
                                        "left": {
                                            "type": "variable",
                                            "value": "handler",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 272,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "Closure",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 272,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 272,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "status",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "call_user_func_array",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "handler",
                                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                    "line": 275,
                                                                    "char": 28
                                                                },
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 275,
                                                                "char": 28
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "array",
                                                                    "left": [
                                                                        {
                                                                            "value": {
                                                                                "type": "variable",
                                                                                "value": "event",
                                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                                "line": 276,
                                                                                "char": 27
                                                                            },
                                                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                            "line": 276,
                                                                            "char": 27
                                                                        },
                                                                        {
                                                                            "value": {
                                                                                "type": "variable",
                                                                                "value": "source",
                                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                                "line": 276,
                                                                                "char": 35
                                                                            },
                                                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                            "line": 276,
                                                                            "char": 35
                                                                        },
                                                                        {
                                                                            "value": {
                                                                                "type": "variable",
                                                                                "value": "data",
                                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                                "line": 276,
                                                                                "char": 41
                                                                            },
                                                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                            "line": 276,
                                                                            "char": 41
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                    "line": 277,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 277,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 277,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 277,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 278,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "method_exists",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "handler",
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 280,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                            "line": 280,
                                                            "char": 42
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "eventName",
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 280,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                            "line": 280,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 280,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 280,
                                                "char": 55
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 282,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 284,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "status",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "handler",
                                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                            "line": 284,
                                                            "char": 38
                                                        },
                                                        "name": "eventName",
                                                        "call-type": 2,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "event",
                                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                    "line": 284,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 284,
                                                                "char": 56
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "source",
                                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                    "line": 284,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 284,
                                                                "char": 64
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "data",
                                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                    "line": 284,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                                "line": 284,
                                                                "char": 70
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 284,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 284,
                                                    "char": 71
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 285,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 288,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "collect",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 288,
                                        "char": 24
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-append",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "responses",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "status",
                                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                        "line": 289,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 289,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 290,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 292,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "cancelable",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 292,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "event",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 294,
                                                    "char": 26
                                                },
                                                "name": "isStopped",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 294,
                                                "char": 39
                                            },
                                            "statements": [
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 296,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 297,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 298,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 300,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "status",
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 300,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 301,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Internal handler to call a queue of events\n     *\n     * @return mixed\n     *",
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 228,
                    "last-line": 305,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getListeners",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 306,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "fireEvents",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 308,
                                    "char": 23
                                },
                                {
                                    "variable": "priorityQueue",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 308,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 309,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "listeners",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 309,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 311,
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
                                        "value": "fireEvents",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 311,
                                        "char": 50
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 311,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "events",
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 311,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 311,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 311,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 311,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 311,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 311,
                                "char": 50
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 312,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 313,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 315,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "listeners",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 315,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 315,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 317,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "priorityQueue",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "variable",
                                            "value": "fireEvents",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 317,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 317,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 317,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 319,
                            "char": 21
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "priorityQueue",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 319,
                                    "char": 23
                                },
                                "name": "top",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 319,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 321,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "priorityQueue",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 321,
                                    "char": 29
                                },
                                "name": "valid",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 321,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "listeners",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "priorityQueue",
                                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                    "line": 322,
                                                    "char": 45
                                                },
                                                "name": "current",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                                "line": 322,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 322,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 324,
                                    "char": 25
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "priorityQueue",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 324,
                                            "char": 27
                                        },
                                        "name": "next",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 324,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 325,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 327,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "listeners",
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 327,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 328,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns all the attached listeners of a certain type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 307,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 307,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 306,
                    "last-line": 333,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getResponses",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 336,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "responses",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 336,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 336,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 337,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns all the responses returned by every handler executed by the last\n     * 'fire' executed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 335,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 335,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 334,
                    "last-line": 341,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasListeners",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 342,
                            "char": 46
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
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 344,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "events",
                                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                                            "line": 344,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 344,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                                        "line": 344,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 344,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 344,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 345,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether certain type of event has listeners\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 343,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 343,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 342,
                    "last-line": 350,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isCollecting",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 353,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "collect",
                                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                                    "line": 353,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 353,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Events\/Manager.zep",
                            "line": 354,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if the events manager is collecting all all the responses returned\n     * by every registered listener in a single fire\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Events\/Manager.zep",
                                "line": 352,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 352,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 351,
                    "last-line": 355,
                    "char": 19
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "DEFAULT_PRIORITY",
                    "default": {
                        "type": "int",
                        "value": "100",
                        "file": "\/app\/phalcon\/Events\/Manager.zep",
                        "line": 27,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Events\/Manager.zep",
                    "line": 31,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Events\/Manager.zep",
            "line": 25,
            "char": 5
        },
        "file": "\/app\/phalcon\/Events\/Manager.zep",
        "line": 25,
        "char": 5
    }
]