[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Events",
        "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Events\\Manager\n *\n * Phalcon Events Manager, offers an easy way to intercept and manipulate, if\n * needed, the normal flow of operation. With the EventsManager the developer\n * can create hooks or plugins that will offer monitoring of data, manipulation,\n * conditional execution and much more.\n *",
        "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
        "line": 21,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ManagerInterface",
        "definition": {
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
                            "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                            "line": 28,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                            "line": 28,
                            "char": 54
                        }
                    ],
                    "docblock": "**\n     * Attach a listener to the events manager\n     *\n     * @param object|callable handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                        "line": 28,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                    "line": 28,
                    "last-line": 34,
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
                            "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                            "line": 35,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                            "line": 35,
                            "char": 54
                        }
                    ],
                    "docblock": "**\n     * Detach the listener from the events manager\n     *\n     * @param object handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                        "line": 35,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                    "line": 35,
                    "last-line": 39,
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
                                "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                                "line": 40,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                            "line": 40,
                            "char": 50
                        }
                    ],
                    "docblock": "**\n     * Removes all events from the EventsManager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                        "line": 40,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                    "line": 40,
                    "last-line": 49,
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
                            "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                            "line": 50,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "source",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                            "line": 50,
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
                                "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                                "line": 50,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                            "line": 50,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Fires an event in the events manager causing the active listeners to be\n     * notified about it\n     *\n     * @param object source\n     * @param mixed  data\n     * @return mixed\n     *",
                    "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                    "line": 50,
                    "last-line": 54,
                    "char": 19
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
                            "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                            "line": 55,
                            "char": 46
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
                                "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                                "line": 55,
                                "char": 56
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                        "line": 55,
                        "char": 56
                    },
                    "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                    "line": 55,
                    "last-line": 59,
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
                            "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                            "line": 60,
                            "char": 46
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
                                "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                                "line": 60,
                                "char": 55
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                        "line": 60,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
                    "line": 60,
                    "last-line": 61,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
            "line": 61,
            "char": 1
        },
        "file": "\/app\/phalcon\/Events\/ManagerInterface.zep",
        "line": 0,
        "char": 0
    }
]