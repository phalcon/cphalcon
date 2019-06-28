[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ControllerInterface",
                "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                "line": 13,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DispatcherInterface",
                "alias": "DispatcherInterfaceBase",
                "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                "line": 14,
                "char": 59
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\DispatcherInterface\n *\n * Interface for Phalcon\\Mvc\\Dispatcher\n *",
        "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
        "line": 21,
        "char": 9
    },
    {
        "type": "interface",
        "name": "DispatcherInterface",
        "extends": [
            {
                "type": "variable",
                "value": "DispatcherInterfaceBase",
                "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                "line": 22,
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
                    "name": "getActiveController",
                    "docblock": "**\n     * Returns the active controller in the dispatcher\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ControllerInterface",
                                    "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                                    "line": 26,
                                    "char": 67
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                                "line": 26,
                                "char": 67
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                        "line": 26,
                        "char": 67
                    },
                    "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                    "line": 26,
                    "last-line": 30,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getControllerName",
                    "docblock": "**\n     * Gets last dispatched controller name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                                "line": 31,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                        "line": 31,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                    "line": 31,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLastController",
                    "docblock": "**\n     * Returns the latest dispatched controller\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ControllerInterface",
                                    "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                                    "line": 36,
                                    "char": 65
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                                "line": 36,
                                "char": 65
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                        "line": 36,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                    "line": 36,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setControllerSuffix",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerSuffix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                            "line": 41,
                            "char": 65
                        }
                    ],
                    "docblock": "**\n     * Sets the default controller suffix\n     *",
                    "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                    "line": 41,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setControllerName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                            "line": 46,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Sets the controller name to be dispatched\n     *",
                    "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                    "line": 46,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaultController",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                            "line": 51,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * Sets the default controller name\n     *",
                    "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
                    "line": 51,
                    "last-line": 52,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
            "line": 52,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/DispatcherInterface.zep",
        "line": 0,
        "char": 0
    }
]