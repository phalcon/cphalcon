[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Events\/EventInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Events",
        "file": "\/app\/phalcon\/Events\/EventInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Events\\EventInterface\n *\n * Interface for Phalcon\\Events\\Event class\n *",
        "file": "\/app\/phalcon\/Events\/EventInterface.zep",
        "line": 18,
        "char": 9
    },
    {
        "type": "interface",
        "name": "EventInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getData",
                    "docblock": "**\n     * Gets event data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                                "line": 23,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                        "line": 23,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getType",
                    "docblock": "**\n     * Gets event type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                                "line": 28,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                        "line": 28,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                    "line": 28,
                    "last-line": 32,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isCancelable",
                    "docblock": "**\n     * Check whether the event is cancelable\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                                "line": 33,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                        "line": 33,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                    "line": 33,
                    "last-line": 37,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isStopped",
                    "docblock": "**\n     * Check whether the event is currently stopped\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                                "line": 38,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                        "line": 38,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                    "line": 38,
                    "last-line": 42,
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
                                "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                                "line": 43,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                            "line": 43,
                            "char": 44
                        }
                    ],
                    "docblock": "**\n     * Sets event data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "EventInterface",
                                    "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                                    "line": 43,
                                    "char": 65
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                                "line": 43,
                                "char": 65
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                        "line": 43,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                    "line": 43,
                    "last-line": 47,
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
                            "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                            "line": 48,
                            "char": 41
                        }
                    ],
                    "docblock": "**\n     * Sets event type\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "EventInterface",
                                    "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                                    "line": 48,
                                    "char": 62
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                                "line": 48,
                                "char": 62
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                        "line": 48,
                        "char": 62
                    },
                    "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                    "line": 48,
                    "last-line": 52,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "stop",
                    "docblock": "**\n     * Stops the event preventing propagation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "EventInterface",
                                    "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                                    "line": 53,
                                    "char": 47
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                                "line": 53,
                                "char": 47
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                        "line": 53,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Events\/EventInterface.zep",
                    "line": 53,
                    "last-line": 54,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Events\/EventInterface.zep",
            "line": 54,
            "char": 1
        },
        "file": "\/app\/phalcon\/Events\/EventInterface.zep",
        "line": 0,
        "char": 0
    }
]