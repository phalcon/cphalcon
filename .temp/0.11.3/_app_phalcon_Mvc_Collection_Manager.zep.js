[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Collection",
        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                "line": 14,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\EventsAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                "line": 15,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                "line": 16,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\CollectionInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                "line": 17,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Collection\\BehaviorInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                "line": 18,
                "char": 45
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
        "line": 40,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Collection\\Manager\n *\n * This components controls the initialization of models, keeping record of relations\n * between the different models of the application.\n *\n * A CollectionManager is injected to a model via a Dependency Injector Container such as Phalcon\\Di.\n *\n * ```php\n * $di = new \\Phalcon\\Di();\n *\n * $di->set(\n *     \"collectionManager\",\n *     function () {\n *         return new \\Phalcon\\Mvc\\Collection\\Manager();\n *     }\n * );\n *\n * $robot = new Robots($di);\n * ```\n *",
        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
        "line": 41,
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
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                "line": 41,
                "char": 49
            },
            {
                "type": "variable",
                "value": "EventsAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                "line": 42,
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
                    "name": "behaviors",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 45,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "connectionServices",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 47,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "container",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 49,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "customEventsManager",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 51,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "eventsManager",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 53,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "implicitObjectsIds",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 55,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "initialized",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 57,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "lastInitialized",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 59,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "serviceName",
                    "default": {
                        "type": "string",
                        "value": "mongo",
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 59,
                        "char": 35
                    },
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 59,
                            "char": 40
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 59,
                            "char": 46
                        }
                    ],
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 63,
                    "char": 6
                }
            ],
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 64,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 64,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 64,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 64,
                            "char": 90
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "entityName",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 66,
                                    "char": 23
                                },
                                {
                                    "variable": "modelsBehaviors",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 66,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 68,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "entityName",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_class_lower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 68,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 68,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 68,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 68,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 73,
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
                                        "value": "modelsBehaviors",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 73,
                                        "char": 64
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 73,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "behaviors",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 73,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 73,
                                            "char": 51
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "entityName",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 73,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 73,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 73,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 73,
                                "char": 64
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "modelsBehaviors",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 74,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 74,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 75,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 80,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable-append",
                                    "operator": "assign",
                                    "variable": "modelsBehaviors",
                                    "expr": {
                                        "type": "variable",
                                        "value": "behavior",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 80,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 80,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 85,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "behaviors",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "entityName",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 85,
                                            "char": 39
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "modelsBehaviors",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 85,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 85,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 86,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Binds a behavior to a model\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 64,
                    "last-line": 90,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 91,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 91,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "customEventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 93,
                                    "char": 32
                                },
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 93,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 95,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "customEventsManager",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 95,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "customEventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 95,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 95,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 95,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 96,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "customEventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 96,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 96,
                                    "char": 40
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 96,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 96,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "className",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "get_class_lower",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "model",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 97,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 97,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 97,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 97,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 98,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "customEventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 98,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "className",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 98,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 98,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 98,
                                        "char": 53
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "customEventsManager",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 99,
                                                    "char": 43
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 99,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 99,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 100,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 101,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 103,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 103,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 104,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a custom events manager related to a model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 91,
                                "char": 80
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 92,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 92,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 91,
                    "last-line": 110,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 111,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 111,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "service",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 113,
                                    "char": 20
                                },
                                {
                                    "variable": "connectionService",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 113,
                                    "char": 39
                                },
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 113,
                                    "char": 51
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 113,
                                    "char": 62
                                },
                                {
                                    "variable": "entityName",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 113,
                                    "char": 74
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 115,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "service",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 115,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "serviceName",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 115,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 115,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 115,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 116,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "connectionService",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 116,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "connectionServices",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 116,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 116,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 116,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 117,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "connectionService",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 117,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 117,
                                    "char": 38
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 117,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 117,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "entityName",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "get_class",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "model",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 118,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 118,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 118,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 118,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 123,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "connectionService",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 123,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "entityName",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 123,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 123,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 123,
                                        "char": 52
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "service",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "connectionService",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 124,
                                                            "char": 48
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "entityName",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 124,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 124,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 124,
                                                    "char": 60
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 125,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 126,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 128,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "container",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 128,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 128,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 128,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 128,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 129,
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
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 129,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 129,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 129,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 129,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 129,
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
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "Exception",
                                                    "dynamic": 0,
                                                    "name": "containerServiceNotFound",
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "the services related to the ORM",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                "line": 133,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 133,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 134,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 134,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 134,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 135,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 140,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "connection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 140,
                                            "char": 36
                                        },
                                        "name": "getShared",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "service",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 140,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 140,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 140,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 140,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 141,
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
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 141,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 141,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 141,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 141,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 141,
                                "char": 49
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
                                                    "value": "Invalid injected connection service",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 142,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 142,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 142,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 143,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 145,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "connection",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 145,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 146,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the connection related to a model\n     *\n     * @return \\Mongo\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 111,
                    "last-line": 150,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getConnectionService",
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 151,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 151,
                            "char": 69
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "service",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 153,
                                    "char": 20
                                },
                                {
                                    "variable": "entityName",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 153,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 155,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "service",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 155,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "serviceName",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 155,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 155,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 155,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 156,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "entityName",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_class",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 156,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 156,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 156,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 156,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 157,
                            "char": 10
                        },
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
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 157,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "connectionServices",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 157,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 157,
                                        "char": 42
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "entityName",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 157,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 157,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 157,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "service",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 158,
                                                        "char": 32
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "connectionServices",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 158,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 158,
                                                    "char": 51
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "entityName",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 158,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 158,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 158,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 159,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 161,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "service",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 161,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 162,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets a connection service for a specific model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 152,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 152,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 151,
                    "last-line": 166,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDI",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 169,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 169,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 169,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 170,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the DependencyInjector container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 168,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 168,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 168,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 167,
                    "last-line": 174,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEventsManager",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 177,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 177,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 177,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 178,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal event manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 176,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 176,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 176,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 175,
                    "last-line": 182,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLastInitialized",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 185,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "lastInitialized",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 185,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 185,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 186,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get the latest initialized model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 184,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 184,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 184,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 183,
                    "last-line": 190,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 191,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 191,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "implicit",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 193,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 198,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "implicit",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 198,
                                    "char": 71
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 198,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "implicitObjectsIds",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 198,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 198,
                                        "char": 52
                                    },
                                    "right": {
                                        "type": "fcall",
                                        "name": "get_class",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 198,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 198,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 198,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 198,
                                    "char": 71
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 198,
                                "char": 71
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "implicit",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 199,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 200,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 202,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 202,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 203,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 192,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 192,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 191,
                    "last-line": 207,
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
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 208,
                            "char": 52
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
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 210,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "initialized",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 210,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 210,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "fcall",
                                        "name": "strtolower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 210,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 210,
                                                "char": 60
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 210,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 210,
                                    "char": 62
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 210,
                                "char": 62
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 211,
                            "char": 5
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 209,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 209,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 208,
                    "last-line": 215,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 216,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 216,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 218,
                                    "char": 22
                                },
                                {
                                    "variable": "initialized",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 218,
                                    "char": 35
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 218,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 220,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "className",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_class_lower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 220,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 220,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 220,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 220,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 221,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "initialized",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 221,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "initialized",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 221,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 221,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 221,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 226,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "initialized",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 226,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "className",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 226,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 226,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 226,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 226,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "method_exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 230,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 230,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "initialize",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 230,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 230,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 230,
                                        "char": 49
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 231,
                                                    "char": 23
                                                },
                                                "name": "initialize",
                                                "call-type": 3,
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 231,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 232,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 237,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "eventsManager",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 237,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "eventsManager",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 237,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 237,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 237,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 238,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 238,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 238,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 238,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 238,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "eventsManager",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 239,
                                                    "char": 31
                                                },
                                                "name": "fire",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "collectionManager:afterInitialize",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 239,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 239,
                                                        "char": 70
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "model",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 239,
                                                            "char": 77
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 239,
                                                        "char": 77
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 239,
                                                "char": 78
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 240,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 242,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "initialized",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 242,
                                                    "char": 44
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "model",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 242,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 242,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 243,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "lastInitialized",
                                            "expr": {
                                                "type": "variable",
                                                "value": "model",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 243,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 243,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 244,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 245,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Initializes a model in the models manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 217,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 216,
                    "last-line": 251,
                    "char": 19
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 252,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 252,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "eventName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 252,
                            "char": 81
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 252,
                            "char": 91
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "behaviors",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 254,
                                    "char": 22
                                },
                                {
                                    "variable": "modelsBehaviors",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 254,
                                    "char": 39
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 254,
                                    "char": 47
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 254,
                                    "char": 62
                                },
                                {
                                    "variable": "behavior",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 254,
                                    "char": 72
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 259,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "behaviors",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 259,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "behaviors",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 259,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 259,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 259,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 260,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "behaviors",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 260,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 260,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 260,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 260,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "modelsBehaviors",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 262,
                                            "char": 73
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "behaviors",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 262,
                                                "char": 48
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "get_class_lower",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "model",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 262,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 262,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 262,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 262,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 262,
                                        "char": 73
                                    },
                                    "statements": [
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "modelsBehaviors",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 267,
                                                "char": 49
                                            },
                                            "value": "behavior",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "result",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "behavior",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                    "line": 268,
                                                                    "char": 43
                                                                },
                                                                "name": "missingMethod",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "model",
                                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                            "line": 268,
                                                                            "char": 63
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                        "line": 268,
                                                                        "char": 63
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "eventName",
                                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                            "line": 268,
                                                                            "char": 74
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                        "line": 268,
                                                                        "char": 74
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "data",
                                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                            "line": 268,
                                                                            "char": 80
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                        "line": 268,
                                                                        "char": 80
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                "line": 268,
                                                                "char": 81
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 268,
                                                            "char": 81
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 269,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "not-identical",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "result",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 269,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "null",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 269,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 269,
                                                        "char": 40
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "return",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "result",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                "line": 270,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 271,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 272,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 273,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 274,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 279,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "eventsManager",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 279,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 279,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 279,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 279,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 280,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 280,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 280,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 280,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 280,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 281,
                                            "char": 34
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "model:",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 281,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "eventName",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 281,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 281,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 281,
                                                "char": 58
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 281,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 281,
                                                "char": 65
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 281,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 281,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 281,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 282,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 284,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 284,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 285,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Dispatch an event to the listeners and behaviors\n     * This method expects that the endpoint listeners\/behaviors returns true\n     * meaning that at least one was implemented\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 253,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 253,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 252,
                    "last-line": 290,
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
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 291,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 291,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 291,
                            "char": 79
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "behavior",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 293,
                                    "char": 21
                                },
                                {
                                    "variable": "behaviors",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 293,
                                    "char": 32
                                },
                                {
                                    "variable": "modelsBehaviors",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 293,
                                    "char": 49
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 293,
                                    "char": 64
                                },
                                {
                                    "variable": "status",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 293,
                                        "char": 79
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 293,
                                    "char": 79
                                },
                                {
                                    "variable": "customEventsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 294,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 296,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "behaviors",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 296,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "behaviors",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 296,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 296,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 296,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 297,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "behaviors",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 297,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 297,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 297,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 297,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "modelsBehaviors",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 298,
                                            "char": 73
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "behaviors",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 298,
                                                "char": 48
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "get_class_lower",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "model",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 298,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 298,
                                                        "char": 70
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 298,
                                                "char": 71
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 298,
                                            "char": 73
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 298,
                                        "char": 73
                                    },
                                    "statements": [
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "modelsBehaviors",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 303,
                                                "char": 49
                                            },
                                            "value": "behavior",
                                            "reverse": 0,
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
                                                                    "value": "behavior",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                    "line": 304,
                                                                    "char": 43
                                                                },
                                                                "name": "notify",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "eventName",
                                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                            "line": 304,
                                                                            "char": 60
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                        "line": 304,
                                                                        "char": 60
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "model",
                                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                            "line": 304,
                                                                            "char": 67
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                        "line": 304,
                                                                        "char": 67
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                "line": 304,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 304,
                                                            "char": 68
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 305,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "status",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 305,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "bool",
                                                            "value": "false",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 305,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 305,
                                                        "char": 41
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "return",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                "line": 306,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 307,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 308,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 309,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 310,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 315,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "eventsManager",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 315,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 315,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 315,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 315,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 316,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 316,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 316,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 316,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 316,
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
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "eventsManager",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 317,
                                                    "char": 40
                                                },
                                                "name": "fire",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "collection:",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                "line": 317,
                                                                "char": 58
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "eventName",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                "line": 317,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 317,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 317,
                                                        "char": 69
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "model",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 317,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 317,
                                                        "char": 76
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 317,
                                                "char": 77
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 317,
                                            "char": 77
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 318,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "status",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 318,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 318,
                                        "char": 24
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "status",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 319,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 320,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 321,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 326,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "customEventsManager",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 326,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "customEventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 326,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 326,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 326,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 327,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "customEventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 327,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 327,
                                    "char": 40
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 327,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 327,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "customEventsManager",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 328,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "get_class_lower",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "model",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 328,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 328,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 328,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 328,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 328,
                                        "char": 66
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
                                                            "value": "customEventsManager",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                            "line": 329,
                                                            "char": 50
                                                        },
                                                        "name": "fire",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": "collection:",
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                        "line": 329,
                                                                        "char": 68
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "eventName",
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                        "line": 329,
                                                                        "char": 79
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                    "line": 329,
                                                                    "char": 79
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                "line": 329,
                                                                "char": 79
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "model",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                    "line": 329,
                                                                    "char": 86
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                                "line": 329,
                                                                "char": 86
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 329,
                                                        "char": 87
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 329,
                                                    "char": 87
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 330,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "status",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 330,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                "line": 330,
                                                "char": 28
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "status",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 331,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 332,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 333,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 334,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 336,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "status",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 336,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 337,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Receives events generated in the models and dispatches them to an events-manager if available\n     * Notify the behaviors that are listening in the model\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 291,
                    "last-line": 341,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 342,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 342,
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
                                "value": "ManagerInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 342,
                                "char": 104
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 342,
                            "char": 105
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "customEventsManager",
                                    "index-expr": [
                                        {
                                            "type": "fcall",
                                            "name": "get_class",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "model",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 344,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 344,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 344,
                                            "char": 55
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 344,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 344,
                                    "char": 72
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 345,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a custom events manager for a specific model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 343,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 342,
                    "last-line": 349,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 350,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 350,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "connectionService",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 350,
                            "char": 96
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "connectionServices",
                                    "index-expr": [
                                        {
                                            "type": "fcall",
                                            "name": "get_class",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "model",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 352,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 352,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 352,
                                            "char": 54
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "connectionService",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 352,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 352,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 353,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a connection service for a specific model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 351,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 350,
                    "last-line": 357,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDI",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 358,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 358,
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
                                    "property": "container",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 360,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 360,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 361,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the DependencyInjector container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 359,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 358,
                    "last-line": 365,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setEventsManager",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventsManager",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ManagerInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 366,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 366,
                            "char": 70
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
                                    "property": "eventsManager",
                                    "expr": {
                                        "type": "variable",
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 368,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 368,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 369,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the event manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 367,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 366,
                    "last-line": 373,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                "line": 374,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 374,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "useImplicitObjectIds",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 374,
                            "char": 96
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "implicitObjectsIds",
                                    "index-expr": [
                                        {
                                            "type": "fcall",
                                            "name": "get_class",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "model",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                        "line": 376,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                                    "line": 376,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                            "line": 376,
                                            "char": 54
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "useImplicitObjectIds",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                        "line": 376,
                                        "char": 78
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                                    "line": 376,
                                    "char": 78
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                            "line": 377,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets whether a model must use implicit objects ids\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                        "line": 375,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
                    "line": 374,
                    "last-line": 378,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
            "line": 41,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Collection\/Manager.zep",
        "line": 41,
        "char": 5
    }
]