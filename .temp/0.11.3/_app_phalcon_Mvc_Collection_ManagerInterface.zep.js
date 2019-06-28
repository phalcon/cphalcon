[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Collection",
        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\AdapterInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                "line": 13,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\CollectionInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                "line": 14,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Collection\\BehaviorInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                "line": 15,
                "char": 45
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "alias": "EventsManagerInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                "line": 16,
                "char": 62
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
        "line": 38,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Collection\\Manager\n *\n * This components controls the initialization of models, keeping record of relations\n * between the different models of the application.\n *\n * A CollectionManager is injected to a model via a Dependency Injector Container such as Phalcon\\Di.\n *\n * ```php\n * $di = new \\Phalcon\\Di();\n *\n * $di->set(\n *     \"collectionManager\",\n *     function() {\n *         return new \\Phalcon\\Mvc\\Collection\\Manager();\n *     }\n * );\n *\n * $robot = new Robots(di);\n * ```\n *",
        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
        "line": 39,
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
                    "name": "addBehavior",
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 44,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 44,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "behavior",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "BehaviorInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 44,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 44,
                            "char": 90
                        }
                    ],
                    "docblock": "**\n     * Binds a behavior to a collection\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                    "line": 44,
                    "last-line": 48,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getConnection",
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 49,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 49,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Returns the connection related to a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "AdapterInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                    "line": 49,
                                    "char": 85
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 49,
                                "char": 85
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                        "line": 49,
                        "char": 85
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                    "line": 49,
                    "last-line": 53,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCustomEventsManager",
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 54,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 54,
                            "char": 71
                        }
                    ],
                    "docblock": "**\n     * Returns a custom events manager related to a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "EventsManagerInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                    "line": 54,
                                    "char": 100
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 54,
                                "char": 100
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                        "line": 54,
                        "char": 100
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                    "line": 54,
                    "last-line": 58,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLastInitialized",
                    "docblock": "**\n     * Get the latest initialized model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                    "line": 59,
                                    "char": 66
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 59,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                        "line": 59,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                    "line": 59,
                    "last-line": 63,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "initialize",
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 64,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 64,
                            "char": 59
                        }
                    ],
                    "docblock": "**\n     * Initializes a model in the models manager\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                    "line": 64,
                    "last-line": 68,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isInitialized",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 69,
                            "char": 52
                        }
                    ],
                    "docblock": "**\n     * Check whether a model is already initialized\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 69,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                        "line": 69,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                    "line": 69,
                    "last-line": 73,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isUsingImplicitObjectIds",
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 74,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 74,
                            "char": 73
                        }
                    ],
                    "docblock": "**\n     * Checks if a model is using implicit object ids\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 74,
                                "char": 82
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                        "line": 74,
                        "char": 82
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                    "line": 74,
                    "last-line": 79,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notifyEvent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 80,
                            "char": 50
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 80,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 80,
                            "char": 79
                        }
                    ],
                    "docblock": "**\n     * Receives events generated in the models and dispatches them to an events-manager if available\n     * Notify the behaviors that are listening in the model\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                    "line": 80,
                    "last-line": 84,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setCustomEventsManager",
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 85,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 85,
                            "char": 71
                        },
                        {
                            "type": "parameter",
                            "name": "eventsManager",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "EventsManagerInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 85,
                                "char": 110
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 85,
                            "char": 111
                        }
                    ],
                    "docblock": "**\n     * Sets a custom events manager for a specific model\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                    "line": 85,
                    "last-line": 89,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setConnectionService",
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 90,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 90,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "connectionService",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 90,
                            "char": 96
                        }
                    ],
                    "docblock": "**\n     * Sets a connection service for a specific model\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                    "line": 90,
                    "last-line": 94,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "useImplicitObjectIds",
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                                "line": 95,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 95,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "useImplicitObjectIds",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                            "line": 95,
                            "char": 96
                        }
                    ],
                    "docblock": "**\n     * Sets if a model must use implicit objects ids\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
                    "line": 95,
                    "last-line": 96,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
            "line": 96,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Collection\/ManagerInterface.zep",
        "line": 0,
        "char": 0
    }
]