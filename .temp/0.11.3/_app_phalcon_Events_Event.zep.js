[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Events\/Event.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Events",
        "file": "\/app\/phalcon\/Events\/Event.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Events\\Event\n *\n * This class offers contextual information of a fired event in the\n * EventsManager\n *",
        "file": "\/app\/phalcon\/Events\/Event.zep",
        "line": 19,
        "char": 5
    },
    {
        "type": "class",
        "name": "Event",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "EventInterface",
                "file": "\/app\/phalcon\/Events\/Event.zep",
                "line": 20,
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
                    "name": "cancelable",
                    "docblock": "**\n     * Is event cancelable?\n     *\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Events\/Event.zep",
                    "line": 32,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "data",
                    "docblock": "**\n     * Event data\n     *\n     * @var mixed\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 33,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Events\/Event.zep",
                    "line": 39,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "source",
                    "docblock": "**\n     * Event source\n     *\n     * @var object\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 40,
                            "char": 28
                        }
                    ],
                    "file": "\/app\/phalcon\/Events\/Event.zep",
                    "line": 46,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "stopped",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Events\/Event.zep",
                        "line": 47,
                        "char": 30
                    },
                    "docblock": "**\n     * Is event propagation stopped?\n     *\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Events\/Event.zep",
                    "line": 53,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "type",
                    "docblock": "**\n     * Event type\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 54,
                            "char": 26
                        }
                    ],
                    "file": "\/app\/phalcon\/Events\/Event.zep",
                    "line": 60,
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
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 61,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "source",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 61,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 61,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 61,
                            "char": 70
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
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 61,
                                "char": 94
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 61,
                            "char": 94
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
                                    "property": "type",
                                    "expr": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Events\/Event.zep",
                                        "line": 63,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 63,
                                    "char": 30
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "source",
                                    "expr": {
                                        "type": "variable",
                                        "value": "source",
                                        "file": "\/app\/phalcon\/Events\/Event.zep",
                                        "line": 64,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 64,
                                    "char": 34
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "data",
                                    "expr": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Events\/Event.zep",
                                        "line": 65,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 65,
                                    "char": 30
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "cancelable",
                                    "expr": {
                                        "type": "variable",
                                        "value": "cancelable",
                                        "file": "\/app\/phalcon\/Events\/Event.zep",
                                        "line": 66,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 66,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 67,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Events\\Event constructor\n     *\n     * @param object source\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Events\/Event.zep",
                        "line": 62,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Event.zep",
                    "line": 61,
                    "last-line": 77,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isCancelable",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 80,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "cancelable",
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 80,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 80,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 81,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether the event is cancelable.\n     *\n     * ```php\n     * if ($event->isCancelable()) {\n     *     $event->stop();\n     * }\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 79,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/Event.zep",
                        "line": 79,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Event.zep",
                    "line": 78,
                    "last-line": 85,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isStopped",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 88,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "stopped",
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 88,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 88,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 89,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether the event is currently stopped.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 87,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/Event.zep",
                        "line": 87,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Event.zep",
                    "line": 86,
                    "last-line": 93,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setData",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 94,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 94,
                            "char": 44
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
                                    "property": "data",
                                    "expr": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Events\/Event.zep",
                                        "line": 96,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 96,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 98,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 98,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 99,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets event data.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "EventInterface",
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 95,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 95,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/Event.zep",
                        "line": 95,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Event.zep",
                    "line": 94,
                    "last-line": 103,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setType",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 104,
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
                                    "property": "type",
                                    "expr": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Events\/Event.zep",
                                        "line": 106,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 106,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 108,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 108,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 109,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets event type.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "EventInterface",
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 105,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 105,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/Event.zep",
                        "line": 105,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Event.zep",
                    "line": 104,
                    "last-line": 119,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "stop",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Events\/Event.zep",
                                            "line": 122,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "cancelable",
                                            "file": "\/app\/phalcon\/Events\/Event.zep",
                                            "line": 122,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Events\/Event.zep",
                                        "line": 122,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 122,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 122,
                                "char": 39
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
                                                    "value": "Trying to cancel a non-cancelable event",
                                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                                    "line": 123,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                                "line": 123,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Events\/Event.zep",
                                        "line": 123,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 124,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 126,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "stopped",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Events\/Event.zep",
                                        "line": 126,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 126,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 128,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 128,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Events\/Event.zep",
                            "line": 129,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Stops the event preventing propagation.\n     *\n     * ```php\n     * if ($event->isCancelable()) {\n     *     $event->stop();\n     * }\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "EventInterface",
                                    "file": "\/app\/phalcon\/Events\/Event.zep",
                                    "line": 121,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Events\/Event.zep",
                                "line": 121,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/Event.zep",
                        "line": 121,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Events\/Event.zep",
                    "line": 120,
                    "last-line": 130,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Events\/Event.zep",
            "line": 19,
            "char": 5
        },
        "file": "\/app\/phalcon\/Events\/Event.zep",
        "line": 19,
        "char": 5
    }
]