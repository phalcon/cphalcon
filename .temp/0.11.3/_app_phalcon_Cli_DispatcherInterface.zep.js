[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Cli",
        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DispatcherInterface",
                "alias": "DispatcherInterfaceBase",
                "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                "line": 13,
                "char": 59
            }
        ],
        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Cli\\Dispatcher\n *",
        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
        "line": 18,
        "char": 9
    },
    {
        "type": "interface",
        "name": "DispatcherInterface",
        "extends": [
            {
                "type": "variable",
                "value": "DispatcherInterfaceBase",
                "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                "line": 19,
                "char": 1
            }
        ],
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActiveTask",
                    "docblock": "**\n     * Returns the active task in the dispatcher\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "TaskInterface",
                                    "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                                    "line": 23,
                                    "char": 55
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                                "line": 23,
                                "char": 55
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                        "line": 23,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLastTask",
                    "docblock": "**\n     * Returns the latest dispatched controller\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "TaskInterface",
                                    "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                                    "line": 28,
                                    "char": 53
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                                "line": 28,
                                "char": 53
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                        "line": 28,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                    "line": 28,
                    "last-line": 32,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOptions",
                    "docblock": "**\n     * Get dispatched options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                                "line": 33,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                        "line": 33,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                    "line": 33,
                    "last-line": 37,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTaskName",
                    "docblock": "**\n     * Gets last dispatched task name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                                "line": 38,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                        "line": 38,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                    "line": 38,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTaskSuffix",
                    "docblock": "**\n     * Gets default task suffix\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                                "line": 43,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                        "line": 43,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                    "line": 43,
                    "last-line": 47,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaultTask",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "taskName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                            "line": 48,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Sets the default task name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                        "line": 48,
                        "char": 60
                    },
                    "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                    "line": 48,
                    "last-line": 52,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                            "line": 53,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Set the options to be dispatched\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                        "line": 53,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                    "line": 53,
                    "last-line": 57,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTaskName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "taskName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                            "line": 58,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Sets the task name to be dispatched\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                        "line": 58,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                    "line": 58,
                    "last-line": 62,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setTaskSuffix",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "taskSuffix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                            "line": 63,
                            "char": 52
                        }
                    ],
                    "docblock": "**\n     * Sets the default task suffix\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                        "line": 63,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
                    "line": 63,
                    "last-line": 64,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
            "line": 64,
            "char": 1
        },
        "file": "\/app\/phalcon\/Cli\/DispatcherInterface.zep",
        "line": 0,
        "char": 0
    }
]